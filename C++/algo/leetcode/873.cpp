// 873. Length of Longest Fibonacci Subsequence [M]
// LeetCode length-of-longest-fibonacci-subsequence

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> valToIdx;
        for(int i = 0; i < n; i ++) valToIdx[arr[i]] = i;
        int memo[n][n];
        memset(memo, -1, sizeof(memo));
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if(j == n || i >= j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int nxtNum = arr[i] + arr[j];
            int ans = 0;
            if(valToIdx.contains(nxtNum)) {
                ans = dfs(j, valToIdx[nxtNum]) + 1;
            }
            return memo[i][j] = ans;
        };
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = i + 1; j < n; j ++) {
                int res = dfs(i, j);
                if(res >= 1) ans = max(ans, res + 2);
            }
        }
        return ans;
    }
};