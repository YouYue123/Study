// 2364. Count Number of Bad Pairs [M]
// LeetCode count-number-of-bad-pairs

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> dict; 
        long long ans = 0;
        for(int i = 0; i < nums.size(); i ++) {
            int key = nums[i] - i;
            ans += i - dict[key];
            dict[key] += 1;
        }
        return ans;
    }
};