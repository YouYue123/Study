// 2044. Count Number of Maximum Bitwise-OR Subsets [M]
// LeetCode count-number-of-maximum-bitwise-or-subsets

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int num : nums) maxOr |= num;
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int i, int curOr) -> void {
            if(i == nums.size()) {
                if (curOr == maxOr) ans += 1;
                return;
            }
            dfs(i + 1, curOr | nums[i]);
            dfs(i + 1, curOr);
        };
        dfs(0, 0);
        return ans;
    }
};