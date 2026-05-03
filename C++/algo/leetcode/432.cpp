// 432. All O`one Data Structure [H]
// LeetCode all-oone-data-structure

// struct  Item {

// }
class AllOne {
private:
    unordered_map<string, int> keyToFreq;
    map<int, unordered_set<string>> freqToKeySet;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        int nxtFreq = 1;
        if(keyToFreq.contains(key)) {
            int prevFreq = keyToFreq[key];
            freqToKeySet[prevFreq].erase(key);
            if(freqToKeySet[prevFreq].empty()) freqToKeySet.erase(prevFreq);
            nxtFreq = prevFreq + 1;
        }
        keyToFreq[key] = nxtFreq;
        freqToKeySet[nxtFreq].insert(key);
    }
    
    void dec(string key) {
        int prevFreq = keyToFreq[key];
        freqToKeySet[prevFreq].erase(key);
        if(freqToKeySet[prevFreq].empty()) freqToKeySet.erase(prevFreq);
        int nxtFreq = prevFreq - 1;
        if(nxtFreq == 0) {
            keyToFreq.erase(key);
        } else {
            keyToFreq[key] = nxtFreq;
            freqToKeySet[nxtFreq].insert(key);
        }
    }
    
    string getMaxKey() {
        if(freqToKeySet.empty()) return "";
        // for(auto& [key, val] : freqToKeySet) {
            // cout << "size: " << key << endl;
            // for(auto& item : val) cout << item << " ";
            // cout << endl;
        // }
        return *(prev(freqToKeySet.end())->second.begin());
    }
    
    string getMinKey() {
        if(freqToKeySet.empty()) return "";
        return *(freqToKeySet.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */