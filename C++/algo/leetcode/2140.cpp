// 2140. Solving Questions With Brainpower [M]
// LeetCode solving-questions-with-brainpower

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector memo(n, -1LL);
        auto dfs = [&](this auto&& dfs, int i) -> long long {
            if(i >= n) return 0LL;
            if(memo[i] != -1LL) return memo[i];
            long long p = questions[i][0], b = questions[i][1];
            return memo[i] = max(
                dfs(i + 1),
                p + dfs(i + b + 1)
            );
        };
        return dfs(0);
    }
};