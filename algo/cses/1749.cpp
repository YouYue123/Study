#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct SegTree {
    int n;
    vector<ll> tree;
    SegTree(int n): n(n) {
        tree.assign(4 * n, 0LL);
        _build(1, 0, n - 1);
    }
    void _build(int node, int left, int right) {
        if(left == right) {
            tree[node] = 1;
            return;
        }
        int mid = left + (right - left) / 2;
        _build(2 * node, left, mid);
        _build(2 * node + 1, mid + 1, right);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int pos, int val) { return _update(1, 0, n - 1, pos, val ); };
    void _update(int node, int left, int right, int pos, int val) {
        if(left == right) {
            tree[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if(pos <= mid) {
            _update(node * 2, left, mid, pos, val);
        } else {
            _update(node * 2 + 1, mid + 1, right, pos, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    int find_kth(int k) { return _find_kth(1, 0, n - 1, k); }
    int _find_kth(int node, int left, int right, int k) { 
        if(left == right) return left;
        int mid = left + (right - left) / 2;
        if(tree[node * 2] >= k) {
            return _find_kth(node * 2, left, mid, k);
        } else {
            return _find_kth(node * 2 + 1, mid + 1, right, k - tree[node * 2]);
        }
    }

};
void solve() {
    int n;
    cin >> n;
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    auto seg_tree = SegTree(n);
    for(int i = 0; i < n; i ++) {
        int p;
        cin >> p;
        int pos = seg_tree.find_kth(p);
        cout << x[pos] << " ";
        seg_tree.update(pos, 0);
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}