#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct SegTree {
    int n;
    vector<ll> tree;
    SegTree(vector<ll>& a): n(a.size()) {
        tree.assign(4 * n, 0LL);
        _build(a, 1, 0, n - 1);
    }

    void _build (vector<ll>& a, int node, int left, int right) {
        if(left == right) {
            tree[node] = a[left];
            return;
        }
        int mid = left + (right - left) / 2;
        _build(a, node * 2, left, mid);
        _build(a, node * 2 + 1, mid + 1, right);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
    
    void update(int pos, ll val) { return _update(1, 0, n - 1, pos, val); }
    void _update(int node, int left, int right, int pos, ll val) {
        if(left == right) {
            tree[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if(pos <= mid) _update(node * 2, left, mid, pos, val);
        else _update(node * 2 + 1, mid + 1, right, pos, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(ll x) { return _query(1, 0, n - 1, x ); }
    ll _query(int node, int left, int right, ll x) {
        if(tree[node] < x) return -1;
        if(left == right) return left;
        int mid = left + (right - left) / 2;
        if(tree[node * 2] >= x) {
            return _query(node * 2, left, mid, x);
        } else {
            return _query(node * 2 + 1, mid + 1, right, x);
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector h(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> h[i];
    auto tree = SegTree(h);
    vector r(m, 0LL);
    for(int i = 0; i < m; i ++) {
        ll r;
        cin >> r;
        auto pos = tree.query(r);
        cout << pos + 1 << " ";
        if(pos != -1) {
            h[pos] -= r;
            tree.update(pos, h[pos]);
        }
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}