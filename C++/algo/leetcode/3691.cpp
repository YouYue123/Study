#include <bits/stdc++.h>
using namespace std;

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

    int query(int left, int right) {
        int k = bit_width((uint32_t)right - left + 1) - 1;
        int min_val = min(f_min[left][k], f_min[right - (1 << k) + 1][k]);
        int max_val = max(f_max[left][k], f_max[right - (1 << k) + 1][k]);
        return max_val - min_val;
    }
};  

struct Item {
    int left;
    int right;
};
struct Compare {
    ST& st;
    Compare(ST& st): st(st) {};
    bool operator () (Item& a, Item& b) {
        return st.query(a.left, a.right) < st.query(b.left, b.right);
    };
};
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        auto st = ST(nums);
        Compare comp(st);
        priority_queue<Item, vector<Item>, Compare> pq(comp);
        for(int left = 0; left < n; left ++) pq.emplace(left, n - 1);
        long long ans = 0;
        int cnt = 0;
        while(cnt < k) {
            auto cur = pq.top();
            pq.pop();
            ans += st.query(cur.left, cur.right);
            if(cur.right > cur.left) pq.emplace(cur.left, cur.right - 1);
            cnt += 1;
        }
        return ans;
    }
};