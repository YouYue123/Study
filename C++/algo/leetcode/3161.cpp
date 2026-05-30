#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> tree;
    BIT (int N) {
        tree.resize(N, 0);
    }
    void update(int idx, vector<int>& a) {
        while(idx < tree.size()) {
            tree[idx] = a[idx];
            for(int i = 1; i < (idx & -idx); i *= 2) {
                tree[idx] = max(tree[idx], tree[idx - i]);
            }
            idx += idx & -idx;
        }
    }

    int query (int idx) {
        int ans = 0;
        while(idx > 0) {
            ans = max(ans, tree[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> insertions;
        insertions.insert(0);
        vector<int> a(1e5 + 1);
        BIT bit(1e5 + 1);
        vector<bool> ans;
        for(auto& q : queries) {
            int type = q[0], x = q[1];
            auto it = insertions.upper_bound(x);
            auto left = *prev(it);
            if(type == 1) {
                if(it != insertions.end()) {
                    auto right = *it;
                    a[right] = right - x;
                    bit.update(right, a);
                }
                a[x] = x - left;
                bit.update(x, a);
                insertions.insert(x);
            } else {
                int sz = q[2];
                if(x - left >= sz) {
                    ans.push_back(true);
                    continue;
                }
                ans.push_back(bit.query(left) >= sz);
            }
        } 
        return ans;     
    }
};