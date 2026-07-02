#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct LazySegmentTree {
    vector<ll> tree;
    vector<ll> lazy;
    LazySegmentTree(int n) {
        tree.assign(4 * n, 0LL);
        lazy.assign(4 * n, 0LL);
    }
};