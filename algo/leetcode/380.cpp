#include <bits/stdc++.h>
using namespace std;

// 380. Insert Delete GetRandom O(1) [M]
// LeetCode insert-delete-getrandom-o1

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> dict;
    mt19937 mt;
public:
    RandomizedSet(): mt(random_device{}()) {
        
    }
    
    bool insert(int val) {
        if(dict.contains(val)) return false;
        nums.push_back(val);
        dict[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!dict.contains(val)) return false;
        int delIdx = dict[val];
        int lastIdx = nums.size() - 1;
        int lastEle = nums[lastIdx];
        swap(nums[delIdx], nums[lastIdx]);
        nums.pop_back();
        dict[lastEle] = delIdx;
        dict.erase(val);
        return true;
    }
    
    int getRandom() {
        auto uni = uniform_int_distribution<>(0, nums.size() - 1);
        return nums[uni(mt)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */