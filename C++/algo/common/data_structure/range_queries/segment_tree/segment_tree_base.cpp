// Segment tree with range sum; supports point update, range query, and binary search.
// query(l, r): sum of a[l..r] (inclusive).
// find_kth(k): smallest index i with prefix sum a[0..i] >= k (non-negative a[i]).
// lower_bound(x): smallest index i with a[i] >= x, or -1 if none exists.

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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Point update: set a[pos] = val and refresh ancestors.
    void update(int pos, ll val) { return _update(1, 0, n - 1, pos, val); }
    void _update(int node, int left, int right, int pos, ll val) {
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
        if(q_left <= left && right <= q_right) return tree[node];
        int mid = left + (right - left) / 2;
        return _query(2 * node, left, mid, q_left, q_right) + _query(2 * node  + 1, mid + 1, right, q_left, q_right);
    }

    // Smallest index i with prefix sum a[0..i] >= k.
    // only valid when saving active range sum
    // int find_kth(int k) { return _find_kth(1, 0, n - 1, k); }
    // int _find_kth(int node, int left, int right, int k) { 
    //     if(left == right) return left;
    //     int mid = left + (right - left) / 2;
    //     // Go left if the left subtree already covers k; otherwise subtract its sum.
    //     if(tree[node * 2] >= k) {
    //         return _find_kth(node * 2, left, mid, k);
    //     } else {
    //         return _find_kth(node * 2 + 1, mid + 1, right, k - tree[node * 2]);
    //     }
    // }

    // Leftmost index with value >= x.
    // only valid when saving range max
    // ll lower_bound(ll x) { return _lower_bound(1, 0, n - 1, x ); }
    // ll _lower_bound(int node, int left, int right, ll x) {
    //     if(tree[node] < x) return -1;          // no element in this range is large enough
    //     if(left == right) return left;
    //     int mid = left + (right - left) / 2;
    //     // Prefer the left child to keep the answer leftmost.
    //     if(tree[node * 2] >= x) {
    //         return _lower_bound(node * 2, left, mid, x);
    //     } else {
    //         return _lower_bound(node * 2 + 1, mid + 1, right, x);
    //     }
    // }
};