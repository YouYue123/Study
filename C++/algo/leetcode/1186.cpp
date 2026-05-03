// 1186. Maximum Subarray Sum with One Deletion [M]
// LeetCode maximum-subarray-sum-with-one-deletion

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int memo[n][2];
        memset(memo, INF, sizeof(memo));
        auto dfs =[&] (this auto&& dfs, int i, int state) {
            if(i < 0) return -INF;
            if(memo[i][state] != INF) return memo[i][state];
            int ans = -INF;
            if(state == 0) {
                ans = max(dfs(i - 1, 0), 0) + arr[i];
            } else if(state == 1) {
                ans = max({
                    max(dfs(i - 1, 1), 0) + arr[i],
                    dfs(i - 1, 0),
                    // dfs(i - 1, 1) + arr[i]
                });
            }
            return memo[i][state] = ans;
        };
        int ans = -INF;
        for(int i = 0; i <  n; i ++) {
            ans = max(ans, dfs(i, 1));
        }
        return ans;
    }
};