#include <bits/stdc++.h>
using namespace std;

// 2906. Construct Product Matrix [M]
// LeetCode construct-product-matrix

int MOD = 12345;
using ull = unsigned long long;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // cout << "size: " << n * m << endl;
        vector pre(n * m, 1LL);
        vector suf(n * m, 1LL);
        auto get_idx = [&] (int i, int j) {
            return i * m + j;
        };
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                int idx = get_idx(i, j);
                if(idx == 0) {
                    pre[idx] = grid[i][j] % MOD;
                } else {
                    pre[idx] = (pre[idx - 1] * grid[i][j]) % MOD;
                }
            }
        }
        // cout << "pre done!" << endl;
        for(int i = n - 1; i >= 0; i --) {
            for(int j = m - 1; j >= 0; j --) {
                int idx = get_idx(i, j);
                if(idx == m * n - 1) {
                    suf[idx] = grid[i][j] % MOD;
                } else {
                    suf[idx] = (suf[idx + 1] * grid[i][j]) % MOD;
                }
            }
        }
        // cout << "suf done!" << endl;
        vector ans(n, vector(m, 0));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                int idx = get_idx(i, j);
                int pre_val = (idx == 0) ? 1 : pre[idx - 1];
                int suf_val = (idx == m * n - 1) ? 1 : suf[idx + 1];
                // cout << i << " " << j << endl;
                // cout << "pre_val: " << pre_val << " suf_val: " << suf_val << endl;
                ans[i][j] = pre_val * suf_val % MOD;
            }
        }
        return ans;
    }
};