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
        while (index > 0) {
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
            for(int i = 1; i < (idx & -idx); i *= 2) {
                tree[idx] = max(tree[idx], tree[idx - i]);
            }
            idx += idx & (-idx);
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