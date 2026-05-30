#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> tree;
    BIT(int N) {
        tree.resize(N + 1, 0);
    }

    void update(int idx, const vector<int>& a) {
        while (idx < tree.size()) {
            tree[idx] = a[idx];
            int managed_len = idx & -idx; 
            for (int len = 1; len < managed_len; len <<= 1) {
                tree[idx] = max(tree[idx], tree[idx - len]); 
            }
            idx += managed_len;
        }
    }

    int query(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans = max(ans, tree[idx]);
            idx -= idx & (-idx);
        }
        return ans;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // 动态寻找 queries 中出现的最大坐标，用来动态开 BIT 空间，防止硬编码越界
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        vector<bool> ans;
        set<int> insertions;
        insertions.insert(0); // 初始左边界
        
        // 空间大小根据最大坐标 max_x 来开即可
        vector<int> a(max_x + 1, 0);
        BIT bit(max_x);

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = insertions.lower_bound(x);
                if (it != insertions.end()) {
                    // 情况 A：x 插入到了两个已有分割点中间
                    int right_nbr = *it;
                    int left_nbr = *prev(it);
                    
                    // 右邻居的左边界变成了 x，间距缩水
                    a[right_nbr] = right_nbr - x;
                    bit.update(right_nbr, a);
                    
                    // x 自己的左边界是原先的 left_nbr
                    a[x] = x - left_nbr;
                    bit.update(x, a);
                } else {
                    // 情况 B：x 插入到了当前所有分割点的最右边
                    int left_nbr = *prev(it);
                    a[x] = x - left_nbr;
                    bit.update(x, a);
                }
                insertions.insert(x);
            } else {
                int x = q[1], sz = q[2];                
                auto it = insertions.upper_bound(x); 
                int left_closest = *prev(it);
                // 【情况①】：检查最右侧残余区间 [left_closest, x] 够不够大
                if (x - left_closest >= sz) {
                    ans.push_back(true);
                    continue;
                }
                // 【情况②】：最右侧不够，去 BIT 里面查 [0, left_closest] 内部的最大间距
                ans.push_back(bit.query(left_closest) >= sz);

            }
        }
        return ans;   
    }
};