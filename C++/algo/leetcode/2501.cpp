// 2501. Longest Square Streak in an Array [M]
// LeetCode longest-square-streak-in-an-array

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        vector memo(maxNum + 1, -1LL);
        auto dfs = [&](this auto&& dfs, long long num) -> long long {
            if(num > maxNum) return 0;
            if(!set.contains(num)) return 0;
            if(memo[num] != -1) return memo[num];
            long long ans = dfs(num * num) + 1;
            return memo[num] = ans;
        };
        long long ans = -1;
        for(int num : nums) {
            ans = max(ans, dfs(num));
        }
        return ans == 1 ? -1 : ans;
    }
};