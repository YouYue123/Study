// 3718. Smallest Missing Multiple of K [E]
// LeetCode smallest-missing-multiple-of-k

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> dict (nums.begin(), nums.end());
        int cur = 1;
        while(true) {
            if(!dict.contains(k * cur)) return k * cur;
            cur += 1;
        }
        return -1;
    }
};