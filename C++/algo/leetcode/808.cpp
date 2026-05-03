// 808. Soup Servings [M]
// LeetCode soup-servings

class Solution {
public:
    vector<vector<double>> memo;
    double dfs(int a, int b) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;
        if(memo[a][b] != -1.0) return memo[a][b];
        return memo[a][b] = 0.25 * dfs(a - 100, b) +
               0.25 * dfs(a - 75, b - 25) +
               0.25 * dfs(a - 50, b - 50) + 
               0.25 * dfs(a - 25, b - 75);
    }
    double soupServings(int n) {
        if(n >= 4451) return 1;
        memo.assign(n + 1, vector<double>(n + 1, -1.0));
        return dfs(n, n);
    }
};