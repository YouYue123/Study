// 3316. Find Maximum Removals From Source String [M]
// LeetCode find-maximum-removals-from-source-string

class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size(), m = pattern.size();
        unordered_set<int> dict(targetIndices.begin(), targetIndices.end());
        vector memo(
            n, 
            vector(m, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(j >= pattern.size()) {
                int cnt = 0;
                while(i < source.size()) {
                    cnt += dict.contains(i);
                    i += 1;
                }
                return cnt;
            };
            if(i >= source.size()) return INT_MIN / 2;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = dfs(i + 1, j) + (dict.contains(i) ? 1 : 0);
            if(source[i] == pattern[j]) {
                ans = max(
                    ans,
                    dfs(i + 1, j + 1)
                );
            } 
            return memo[i][j] = ans;
        };
        return dfs(0, 0);
    }
};