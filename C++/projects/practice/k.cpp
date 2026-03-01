#include <future>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <mutex>
#include <thread>
#include <chrono>
#include <functional>
using namespace std;
// ==========================================
// 1. 抽象缓存接口 (Blackbox Cache)
// ==========================================
// class ICache {
// public:
//     virtual ~ICache() = default;
//     virtual string get(const std::string& key) = 0;
//     virtual void put(const std::string& key, const std::string& value) = 0;
//     virtual void resize(size_t new_capacity) = 0;
//     virtual size_t get_size() = 0;
// };

class ICache {
    public:
        virtual string get(const string& key) = 0;
        virtual void put(const string& key, const string& val) = 0;
        virtual void resize(int new_capacity) = 0;
        virtual int get_capacity() = 0;
};

class SimpleCache : public ICache {
    string name;
    size_t capacity;
    unordered_map<string, string> data;
public:
    SimpleCache(string n, size_t cap) : name(n), capacity(cap) {}

    string get(const string& key) override {
        if (data.contains(key)) return data[key];
        return "";
    }

    void put(const string& key, const string& value) override {
        if (data.size() >= capacity && data.find(key) == data.end()) {
            data.erase(data.begin());
        }
        data[key] = value;
    }
    void resize(int new_capacity) override {
        while(data.size() > new_capacity) {
            data.erase(data.begin()->first);
        }
        this->capacity = new_capacity;
    }
    int get_capacity() override {
        return capacity;   
    }
};

class MultiCache;

class AsyncServer: public enable_shared_from_this<AsyncServer> {
public:
    void request(string key, weak_ptr<MultiCache> callback_obj);
};


struct RequestItem {
    shared_ptr<promise<string>> prom;
    shared_future<string> futu;
};


class MultiCache: public std::enable_shared_from_this<MultiCache> {
private:
    mutex mtx;
    ICache *cacheA, *cacheB;
    AsyncServer server;
    unordered_map<string, RequestItem> inflight_requests;
    const string PENDING = "__PENDING__";
    atomic<long> hitsA {0}, hitsB{0};
    int total_capacity;
public:
    MultiCache(ICache* a, ICache* b) : cacheA(a), cacheB(b) {}

    shared_future<string> query(string key) {
        lock_guard<mutex> lock(mtx);
        
        // 1. 检查缓存
        string valA = cacheA->get(key);
        if(valA != "" && valA != PENDING) {
            hitsA += 1;
            promise<string> p;
            p.set_value(valA);
            if(shouldRebalance()) rebalance();
            return p.get_future().share();
        }
        string valB = cacheB->get(key);
        if(valB != "" && valB != PENDING) {
            hitsB += 1;
            promise<string> p;
            p.set_value(valB);
            if(shouldRebalance()) rebalance();
            return p.get_future().share();
        }

        if(inflight_requests.contains(key)) {
             cout << "[MultiCache] Collapsing request for: " << key << endl;
            return inflight_requests[key].futu;
        }

        // 3. 发起新请求
        cout << "[MultiCache] New server request for: " << key << endl;
        
        // Follow-up 2: 占位
        cacheA->put(key, PENDING);
        cacheB->put(key, PENDING);

        // 使用 shared_ptr 管理 promise 生命周期
        auto p = make_shared<promise<string>>();
        inflight_requests[key] = { p, p->get_future().share() };
        std::weak_ptr<MultiCache> self_weak = shared_from_this();
        server.request(key, self_weak);
        return inflight_requests[key].futu;
    }

    void on_server_response(string key, string value) {
        
        {
            lock_guard<mutex> lock(mtx);
            if(!inflight_requests.contains(key)) return;
            cacheA->put(key, value);
            cacheB->put(key, value);
            auto& prom = inflight_requests[key].prom;
            prom->set_value(value);
            inflight_requests.erase(key);
        }
    }

    bool shouldRebalance() {
        double rateA = (double) hitsA / (hitsA + hitsB);
        return rateA > 0.7 || rateA < 0.3;
    } 

    void rebalance () {
        double rateA = (double) hitsA / (hitsA + hitsB);
        int newCapA;
        if(rateA > 0.7) {
            newCapA = total_capacity * 0.8;
        } else if(rateA < 0.3) {
            newCapA = total_capacity * 0.2;
        } else {
            newCapA = total_capacity * 0.5;
        }
        int newCapB = total_capacity - newCapA;
        cacheA->resize(newCapA);
        cacheB->resize(newCapB);
        hitsA = 0;
        hitsB = 0;
    }
};

// --- AsyncServer 模拟实现 ---
void AsyncServer::request(string key, weak_ptr<MultiCache> callback_obj) {
    thread([=]() {
        if(auto shared_mc = callback_obj.lock()) {
            shared_mc->on_server_response(key, "test value");
        }
    }).detach();
}

// ==========================================
// 3. 测试用例
// ==========================================
int main() {
    SimpleCache lru("LRU", 10);
    SimpleCache lfu("LFU", 10);
    auto mc = make_shared<MultiCache>(&lru, &lfu);    
    const string targetKey = "shared_user_data";
    const int numThreads = 5;
    vector<thread> workers;
    cout << "=== Test 1: Request Collapsing (Follow-up 1) ===" << endl;
    cout << "Starting " << numThreads << " threads to query '" << targetKey << "' simultaneously..." << endl;
    for(int i = 0; i < numThreads; i ++) {
        workers.emplace_back([&] {
            auto fut = mc->query(targetKey);
            string result = fut.get();
            cout << "result: " << result << endl;
        });
    }

    // 等待所有线程完成
    for (auto& t : workers) {
        if(t.joinable()) t.join();
    }

    cout << "\n=== Test 2: Sequential Query (Cache Hit) ===" << endl;
    cout << "Querying '" << targetKey << "' again, should be a direct cache hit..." << endl;
    auto fut_hit = mc->query(targetKey);
    cout << "Instant Result: " << fut_hit.get() << endl;

    return 0;
}
