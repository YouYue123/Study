#include <bits/stdc++.h>
using namespace std;

int constexpr INF = 0x3f3f3f3f;
struct ST {
    vector<vector<int>> f;
    ST (vector<int>& nums) {
        int n = nums.size();
        int w = bit_width((uint32_t) n);
        f.resize(n, vector(w, 0));
        for(int i = 0; i < n; i ++) {
            f[i][0] = nums[i];
        }
        for(int k = 1; k < w; k ++) {
            int last_idx = n - (1 << k);
            for(int i = 0; i <= last_idx; i ++) {
                int mid = i + (1 << (k - 1));
                f[i][k] = f[i][k - 1] | f[mid][k - 1];
            }
        }
    }

    int query(int l, int r) {
        int k = bit_width((uint32_t) r - l + 1) - 1;
        return f[l][k] | f[r - (1 << k) + 1][k];
    }
};
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        auto st = ST(nums);
        int ans = INF;
        for(int i = 0 ; i < n; i ++) {
            int left = i - 1, right = n;
            auto is_valid = [&] (int x) -> bool {
                return st.query(i, x) >= k;
            };
            while(left + 1 < right) {
                int mid = left + (right - left) / 2;
                if(is_valid(mid)) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            if(left >= i) {
                ans = min(ans, abs(k - st.query(i, left)));
            }
            if(right < n) {
                ans = min(ans, abs(k - st.query(i, right)));
            }
        }  
        return ans;      
    }
};