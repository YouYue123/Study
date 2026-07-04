// Segment tree with range sum; supports point update and range query.
// query(l, r): sum of a[l..r] (inclusive).

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegmentTree {
    int n;
    vector<ll> tree;
    SegmentTree(vector<ll>& a): n(a.size()) {
        tree.assign(4 * n, 0);
        _build(a, 1, 0, n - 1);
    }

    void _build (vector<ll>& a, int node, int left, int right) {
        if(left == right) {
            tree[node] = a[left];
            return;
        }
        int mid = left + (right - left) / 2;
        _build(a, 2 * node, left, mid);
        _build(a, 2 * node + 1, mid + 1, right);
    }

    // Point update: set a[pos] = val and refresh ancestors.
    void update(int pos, ll val) { return _update(1, 0, n - 1, pos, val); }
    void _update(int node, int left, int right, int pos, int val) {
        if(left == right) {
            tree[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if(pos <= mid) {
            _update(2 * node, left, mid, pos, val);
        } else {
            _update(2 * node + 1, mid + 1, right, pos, val);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    
    // Range sum on [q_left, q_right].
    ll query(int q_left, int q_right) { return _query(1, 0, n - 1, q_left, q_right); }
    ll _query (int node, int left, int right, int q_left, int q_right) {
        if(q_right < left || q_left > right) return 0;   // no overlap
        if(q_left <= left && q_right <= right) return tree[node];
        int mid = left + (right - left) / 2;
        return _query(2 * node, left, mid, q_left, q_right) + _query(2 * node  + 1, mid + 1, right, q_left, q_right);
    }
};