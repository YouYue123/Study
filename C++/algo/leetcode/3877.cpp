// 3877. Minimum Removals to Achieve Target XOR [M]
// LeetCode minimum-removals-to-achieve-target-xor

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        vector memo(
            n,
            unordered_map<int, int>()
        );
        auto dfs = [&] (this auto&& dfs, int i, int sum) {
            if(i == n) {
                if(sum == target) return 0;
                return INF;
            } 
            if(memo[i].contains(sum)) return memo[i][sum];
            return memo[i][sum] = min(
                dfs(i + 1, sum ^ nums[i]),
                dfs(i + 1, sum) + 1
            );
        };
        int ans = dfs(0, 0);
        return ans >= INF ? -1 : ans;
    }
};