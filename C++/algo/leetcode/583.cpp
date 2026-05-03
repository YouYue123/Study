// 583. Delete Operation for Two Strings [M]
// LeetCode delete-operation-for-two-strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector memo(
            n,
            vector(m, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == n || j == m) return n - i + m - j;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            if(word1[i] == word2[j]) {
                ans = dfs(i + 1, j + 1);
            } else {
                ans = min(
                    dfs(i + 1, j),
                    dfs(i, j + 1)
                ) + 1; 
            }
            return memo[i][j] =  ans;
        };
        return dfs(0, 0);
    }
};