// 460. LFU Cache [H]
// LeetCode lfu-cache

class LFUCache {
public:
    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;
    int cap;
    int minFreq;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (!keyToVal.count(key)) return -1;
        increaseFreq(key);
        return keyToVal[key];
    }
    
    void put(int key, int val) {
        if (cap <= 0) return;

        if (keyToVal.count(key)) {
            keyToVal[key] = val;
            increaseFreq(key);
            return;
        }

        if (cap == keyToVal.size()) {
            removeMinFreqKey();
        }

        keyToVal[key] = val;
        keyToFreq[key] = 1;
        freqToKeys[1].push_back(key);
        keyToIter[key] = prev(freqToKeys[1].end());
        minFreq = 1;
    }

private:
    void increaseFreq(int key) {
        int freq = keyToFreq[key];
        auto& oldList = freqToKeys[freq];
        oldList.erase(keyToIter[key]);
        
        freqToKeys[freq + 1].push_back(key);
        keyToFreq[key] = freq + 1;
        keyToIter[key] = prev(freqToKeys[freq + 1].end());

        if (oldList.empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq = freq + 1;
        }
    }

    void removeMinFreqKey() {
        auto& list = freqToKeys[minFreq];
        int keyToRemove = list.front();
        list.pop_front();
        if (list.empty()) {
            freqToKeys.erase(minFreq);
        }
        keyToVal.erase(keyToRemove);
        keyToFreq.erase(keyToRemove);
        keyToIter.erase(keyToRemove);
    }
};
