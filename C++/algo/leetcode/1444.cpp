// 1444. Number of Ways of Cutting a Pizza [H]
// LeetCode number-of-ways-of-cutting-a-pizza

int MOD = 1e9 + 7;
struct MatrixSum {
    vector<vector<int>> presum;
    MatrixSum(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        presum.resize(m + 1);
        for(int i = 0; i <= m; i ++) presum[i].resize(n + 1);
        // vector cur(m + 1, vector(n + 1, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                presum[i + 1][j + 1] = presum[i][j + 1] + presum[i + 1][j] - presum[i][j] + (matrix[i][j] == 'A' ? 1 : 0);
            }
        }
    }

    // (c1, r1) topLeft, (c2, r2) bottomRight
    bool hasApple(int r1, int c1, int r2, int c2) {
        // cout << c1 << " " << r1 << " " << c2 << " " << r2 << endl;
        return (presum[r2][c2] - presum[r2][c1] - presum[r1][c2] + presum[r1][c1]) > 0;
    }
};
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        MatrixSum ms(pizza);
        // cout << ms.hasApple(0, 0, m, n);
        vector memo(m, vector(n, vector(k, -1)));
        auto dfs = [&](this auto&& dfs, int i, int j, int cnt) {
            if(cnt == k - 1) return ms.hasApple(i, j, m, n) ? 1 : 0;
            if(memo[i][j][cnt] != -1) return memo[i][j][cnt];
            int ans = 0;
            for(int nxtI = i + 1; nxtI < m; nxtI ++) {
                if(ms.hasApple(i, j, nxtI, n)) {
                    ans = (ans + dfs(nxtI, j, cnt + 1)) % MOD;
                }
            }
            for(int nxtJ = j + 1; nxtJ < n; nxtJ ++) {
                if(ms.hasApple(i, j, m, nxtJ)) {
                    ans = (ans + dfs(i, nxtJ, cnt + 1)) % MOD;
                }
            }
            return memo[i][j][cnt] = ans;
        };

        return dfs(0, 0, 0);
    }
};