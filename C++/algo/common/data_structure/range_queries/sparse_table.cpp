#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/sparse-table/
 // 稀疏表：预处理静态区间最值，O(n log n) 建表，O(1) 查询（可重复贡献的 RMQ, eg min, max, etc)
struct ST {
    // f[i][k]：区间 [i, i+2^k-1] 的contribution
    vector<vector<int>> f_min;
    vector<vector<int>> f_max;

    ST (vector<int>& nums) {
        int n = nums.size();
        // 层数：覆盖长度 n 所需的最大 log2 向上取整
        int w = __lg(n) + 1;        
        f_min.resize(n, vector(w, 0));            
        f_max.resize(n, vector(w, 0));
        // k = 0：长度为 1 的区间，直接等于原数组
        for(int i = 0; i < n; i ++) {
            f_min[i][0] = nums[i];
            f_max[i][0] = nums[i];
        }
        // k >= 1：将长度为 2^k 的区间拆成左右各 2^(k-1)，由子区间合并
        for(int k = 1; k < w; k ++) {
            for(int i = 0; i < n; i ++) {
                // 右半段起点 i + 2 ^ k - 1
                int mid = i + (1 << (k - 1));   
                if(mid >= n) break; 
                f_min[i][k] = min(f_min[i][k - 1], f_min[mid][k - 1]);
                f_max[i][k] = max(f_max[i][k - 1], f_max[mid][k - 1]);
            }
        }
    }

    // 查询 [left, right] 最小值：取不超过区间长度的最大 2^k，用左端一块 + 右端一块覆盖（可重叠，min 可重复贡献）
    int query_min(int left, int right) {
        int k = __lg((right - left + 1));  // 2^k <= 区间长度 < 2^(k+1)
        return min(f_min[left][k], f_min[right - (1 << k) + 1][k]);  // 左对齐块与右对齐块
    }
    // 查询 [left, right] 最大值，同上
    int query_max(int left, int right) {
        int k = __lg(right - left + 1);  // 2^k <= 区间长度 < 2^(k+1)
        return max(f_max[left][k], f_max[right - (1 << k) + 1][k]);  // 左对齐块与右对齐块
    }
};  
