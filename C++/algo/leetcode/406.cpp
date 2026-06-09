#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> tree;
    BIT(int N) {
        tree.resize(N + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void update (int idx, int val) {
        while(idx < tree.size()) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }
    
    int query(int idx) {
        int ans = 0;
        while(idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [&] (auto& a, auto& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> ans(n, { -1, -1 });
        auto bit = BIT(n);
        for(int i = 1; i <= n; i ++) bit.update(i, 1);
        for(auto& p : people) {
            int h = p[0], k = p[1];
            // cout << "h: " << h << " k : " << k << endl; 
            int left = 0, right = n + 1;
            while(left + 1 < right) {
                int mid = left + (right - left) / 2;
                if(bit.query(mid) > k) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            ans[left] = p;
            bit.update(left + 1, -1);
        }
        return ans;
    }
};