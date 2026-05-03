// 3759. Count Elements With at Least K Greater Values [M]
// LeetCode count-elements-with-at-least-k-greater-values

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dict;
        for(int num : nums) dict[num] += 1;
        for(auto& [num, freq] : dict) {
            int cnt = nums.end() - upper_bound(nums.begin(), nums.end(), num);
            if(cnt >= k) ans += freq;
        }
        return ans;
    }
};