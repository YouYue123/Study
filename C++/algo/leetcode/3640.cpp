// 3640. Trionic Array II [H]
// LeetCode trionic-array-ii

long long constexpr INF = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector memo(n, vector(4, -INF));
        // 0: has not started
        // 1: first increasing
        // 2: dereasing
        // 3: second increasing
        auto dfs = [&](this auto&& dfs, int i, int state) -> long long {
            if(i == n) return state == 3 ? 0 : -INF;
            if(memo[i][state] != -INF) return memo[i][state];
            long long ans = -INF;
            if(state == 0) {
                ans = dfs(i + 1, 0);
                if(nums[i] > nums[i - 1]) {
                    ans = max(ans, nums[i - 1] + nums[i] + dfs(i + 1, 1));
                }
            } else if(state == 1) {
                if(nums[i] > nums[i - 1]) {
                    ans = nums[i] + dfs(i + 1, 1);
                } else if (nums[i] < nums[i - 1]){
                    ans = nums[i] + dfs(i + 1, 2);
                }
            } else if(state == 2) {
                if(nums[i] < nums[i - 1]) {
                    ans = nums[i] + dfs(i + 1, 2);
                } else if(nums[i] > nums[i - 1]) {
                    ans = nums[i] + dfs(i + 1, 3);
                }
            } else if(state == 3) {
                if (nums[i] > nums[i - 1]) {
                    ans = max(0LL, nums[i] + dfs(i + 1, 3));
                } else {
                    return 0;
                }
            }
            return memo[i][state] = ans;
        };
        return dfs(1, 0);
    }
};