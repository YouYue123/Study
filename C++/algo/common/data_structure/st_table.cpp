#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/sparse-table/

class ST {
    vector<vector<int>> st_min;
    vector<vector<int>> st_max;

public:
    // 时间复杂度 O(n * log n)
    ST(const vector<int>& nums) {
        int n = nums.size();
        int w = bit_width((uint32_t) n);
        st_min.resize(w, vector<int>(n));
        st_max.resize(w, vector<int>(n));

        for (int j = 0; j < n; j++) {
            st_min[0][j] = nums[j];
            st_max[0][j] = nums[j];
        }

        for (int i = 1; i < w; i++) {
            for (int j = 0; j <= n - (1 << i); j++) {
                st_min[i][j] = min(st_min[i - 1][j], st_min[i - 1][j + (1 << (i - 1))]);
                st_max[i][j] = max(st_max[i - 1][j], st_max[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    int query_min(int l, int r) const {
        int k = bit_width((uint32_t) r - l) - 1;
        return min(st_min[k][l], st_min[k][r - (1 << k)]);
    }

    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    int query_max(int l, int r) const {
        int k = bit_width((uint32_t) r - l) - 1;
        return max(st_max[k][l], st_max[k][r - (1 << k)]);
    }
};

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
