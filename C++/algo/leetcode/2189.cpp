// 2189. Number of Ways to Build House of Cards [M]
// LeetCode number-of-ways-to-build-house-of-cards

class Solution {
public:
    int houseOfCards(int n) {
        vector memo(n + 1, vector(n + 2, -1));
        auto dfs = [&] (this auto&& dfs, int i, int lastRow) {
            if(i == 0 || i == 2) return 1;
            // cout << i << " " << lastRow << endl;
            if(memo[i][lastRow] != -1) return memo[i][lastRow];
            int ans = 0;
            for(int j = 5; j <= i && j < lastRow; j += 3) {
                ans += dfs(i - j, j);
            }
            return memo[i][lastRow] = ans;
        };

        return dfs(n, n + 1);
    }
};