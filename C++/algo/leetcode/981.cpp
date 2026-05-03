// 981. Time Based Key-Value Store [M]
// LeetCode time-based-key-value-store

struct Item {
    string value;
    int timestamp;
};
class TimeMap {
private:
    unordered_map<string, vector<Item>> dict;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        auto& items = dict[key];
        int n = items.size();
        int left = -1, right = items.size();
        auto isValid = [&] (int x) {
            return items[x].timestamp <= timestamp;
        };
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if(left >= items.size()) return "";
        return items[left].value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */