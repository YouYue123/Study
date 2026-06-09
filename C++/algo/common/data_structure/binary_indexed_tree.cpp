#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/fenwick/
// Binary Indexed Tree (also known as Fenwick Tree) data structure
struct BIT {
    vector<int> tree;
    BIT(int N){
        tree.assign(N + 1, 0);
    }
    int lowbit(int i) {
        // x 的二进制中，最低位的 1 以及后面所有 0 组成的数．
        // lowbit(0b01011000) == 0b00001000
        //          ~~~~^~~~
        // lowbit(0b01110010) == 0b00000010
        //          ~~~~~~^~
        return i & (-i);
    }
    void update(int idx, int delta) {
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += lowbit(idx);
        }
    }
    int query(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx); 
        }
        return ans;
    }
};

struct MAX_BIT {
    vector<int> tree;
    MAX_BIT(int N) {
        tree.resize(N + 1, 0);
    }

    void update(int idx, vector<int>& a) {
        while(idx < tree.size()) {
            tree[idx] = a[idx];
            // 总共管辖的长度
            int managed_len = idx & -idx; 
            // i 代表当前派出的“侦察兵”的跨度，从 1 开始，每次翻倍
            for(int len = 1; len < managed_len; len <<= 1) {
                // 侦察兵从右往左跳跃，去拿左边下属 tree[idx - i] 的账本
                tree[idx] = max(tree[idx], tree[idx - len]); 
            }
            idx += managed_len;
        }
    }

    int query (int idx) {
        int ans = 0;
        while(idx > 0) {
            ans = max(ans, tree[idx]);
            idx -= idx & (-idx);
        }
        return ans;
    }
};