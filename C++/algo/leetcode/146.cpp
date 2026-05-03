// 146. LRU Cache [M]
// LeetCode lru-cache

struct Node {
    int key;
    int val;
};

class LRUCache {
private:
    list<Node> data;
    unordered_map<int, list<Node>::iterator> dict;
    int capacity;
public:
    LRUCache(int capacity): capacity(capacity) {
        
    }
    
    int get(int key) {
        if(!dict.contains(key)) return -1;
        auto it = dict[key];
        int val = it->val;
        data.erase(it);
        data.emplace_back(key, val);
        dict[key] = prev(data.end());
        return val;
    }
    
    void put(int key, int value) { 
        if(!dict.contains(key)) {
            if(dict.size() == capacity) {
                auto front = data.front();
                dict.erase(front.key);
                data.pop_front();
            }
        } else {
            auto it = dict[key];
            data.erase(it);
            dict.erase(key);
        }
        data.emplace_back(key, value);
        dict[key] = prev(data.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */