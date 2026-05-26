#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/sparse-table/
struct ST2D {
    int n, m;
    vector<vector<array<array<int, 8>, 8>>> st;

    ST2D(const vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int wn = bit_width(1u * n);
        int wm = bit_width(1u * m);

        st.assign(n, vector<array<array<int, 8>, 8>>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                st[i][j][0][0] = matrix[i][j];

        // 预处理 ST 表
        for (int k2 = 1; k2 < wm; k2++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= m - (1 << k2); j++) {
                    st[i][j][0][k2] = max(st[i][j][0][k2 - 1], st[i][j + (1 << (k2 - 1))][0][k2 - 1]);
                }
            }
        }

        for (int k1 = 1; k1 < wn; k1++) {
            for (int k2 = 0; k2 < wm; k2++) {
                for (int i = 0; i <= n - (1 << k1); i++) {
                    for (int j = 0; j <= m - (1 << k2); j++) {
                        st[i][j][k1][k2] = max(st[i][j][k1 - 1][k2], st[i + (1 << (k1 - 1))][j][k1 - 1][k2]);
                    }
                }
            }
        }
    }

    // 查询范围 [r1, r2) x [c1, c2)
    int query(int r1, int c1, int r2, int c2) const {
        r1 = max(r1, 0); c1 = max(c1, 0);
        r2 = min(r2, n); c2 = min(c2, m);
        if (r1 >= r2 || c1 >= c2) return -1;
        
        int k1 = bit_width(1u * (r2 - r1)) - 1;
        int k2 = bit_width(1u * (c2 - c1)) - 1;
        
        return max({
            st[r1][c1][k1][k2],
            st[r2 - (1 << k1)][c1][k1][k2],
            st[r1][c2 - (1 << k2)][k1][k2],
            st[r2 - (1 << k1)][c2 - (1 << k2)][k1][k2]
        });
    }
};
