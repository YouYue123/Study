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
        return i & (-i);
    }
    void add(int idx, int delta) {
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