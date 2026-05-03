// 2336. Smallest Number in Infinite Set [M]
// LeetCode smallest-number-in-infinite-set

class SmallestInfiniteSet {
public:
    set<int> dict;
    int thres = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(dict.empty()) {
            int ans = thres;
            thres += 1;
            return ans;
        }
        int ans = *dict.begin();
        dict.erase(*dict.begin());
        return ans;
    }
    
    void addBack(int num) {
        if(num < thres) {
            dict.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */