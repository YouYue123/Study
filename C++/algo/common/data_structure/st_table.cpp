#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/sparse-table/

struct ST {
    // f[i][k] stands for range val of [i, i + 2 ^ k - 1]
    vector<vector<int>> f;
    ST(vector<int>& nums) {
        int n = nums.size();
        int w = bit_width((uint32_t) n);
        f.resize(n, vector<int>(w));
        for(int i = 0; i < n; i ++) {
            f[i][0] = nums[i];
        }
        for(int k = 1; k < w; k ++) {
            int last_idx = n - (1 << k);
            for(int i = 0; i <= last_idx; i ++) {
                int mid = i + (1 << (k - 1));
                f[i][k] = max(f[i][k - 1], f[mid][k - 1]);
            }
        }
    }
    
    // [l, r]
    int query (int l, int r) {
        int k = bit_width((uint32_t) r - l + 1) - 1;
        return max(f[l][k], f[r - (1 << k) + 1][k]);
    }
};