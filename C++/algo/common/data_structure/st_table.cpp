#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/sparse-table/

struct ST {
    vector<vector<int>> f_min;
    vector<vector<int>> f_max;
    ST (vector<int>& nums) {
        int n = nums.size();
        int w = bit_width((uint32_t)n);
        f_min.resize(n, vector(w, 0));
        f_max.resize(n, vector(w, 0));
        for(int i = 0; i < n; i ++) {
            f_min[i][0] = nums[i];
            f_max[i][0] = nums[i];
        }
        for(int k = 1; k < w; k ++) {
            int last_idx = n - (1 << k);
            for(int i = 0; i <= last_idx; i ++) {
                int mid = i + (1 << (k - 1));
                f_min[i][k] = min(f_min[i][k - 1], f_min[mid][k - 1]);
                f_max[i][k] = max(f_max[i][k - 1], f_max[mid][k - 1]);
            }
        }
    }

    int query_min(int left, int right) {
        int k = bit_width((uint32_t)right - left + 1) - 1;
        return min(f_min[left][k], f_min[right - (1 << k) + 1][k]);
    }
    int query_max(int left, int right) {
        int k = bit_width((uint32_t)right - left + 1) - 1;
        return max(f_max[left][k], f_max[right - (1 << k) + 1][k]);
    }
};  
