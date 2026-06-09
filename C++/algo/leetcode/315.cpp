#include <bits/stdc++.h>
using namespace std;

// 315. Count of Smaller Numbers After Self [H]
// LeetCode count-of-smaller-numbers-after-self

struct BIT {
    vector<int> tree;
    BIT(int n) {
        tree.resize(n + 1);
    }
    int lowbit (int x) {
        return x & -x;
    }
    void update(int idx, int val) {
        while(idx < tree.size()) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }

    int query (int idx) {
        int ans = 0;
        while(idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
};
int constexpr DELTA = 1e4 + 1;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        auto bit = BIT(max_val + DELTA + 1);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i --) {
            ans[i] = bit.query(nums[i] + DELTA - 1);
            bit.update(nums[i] + DELTA, 1);
        }
        return ans;
    }
};