// 740. Delete and Earn [M]
// LeetCode delete-and-earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(int num : nums) cnt[num] += 1;
        sort(nums.begin(), nums.end());
        vector<int> memo(nums.size() + 1, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i >= nums.size()) return 0;
            if(memo[i] != -1) return memo[i];
            int num = nums[i];
            int j = upper_bound(nums.begin(), nums.end(), num + 1) - nums.begin();
            return memo[i] = max(
                dfs(j) + cnt[num] * num,
                dfs(i + 1)
            );
        };

        return dfs(0);
    }
};