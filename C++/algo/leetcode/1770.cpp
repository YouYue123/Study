// 1770. Maximum Score from Performing Multiplication Operations [H]
// LeetCode maximum-score-from-performing-multiplication-operations

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();

        vector memo(m, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int leftCnt) {
            if(i == m) return 0;
            int rightCnt = i - leftCnt;
            if(memo[i][leftCnt] != -1) return memo[i][leftCnt];
            int ans = max(
                dfs(i + 1, leftCnt + 1) + multipliers[i] * nums[leftCnt],
                dfs(i + 1, leftCnt) + multipliers[i] * nums[n - 1 - rightCnt]
            );
            return memo[i][leftCnt] = ans;
        };

        return dfs(0, 0);
    }
};