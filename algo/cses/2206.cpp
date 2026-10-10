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
        tree.resize(n * 4);
        _build(a, 1, 0, n - 1);
    };

    void _build(vector<ll>& a, int node, int left, int right) {
        if(left == right) {
            tree[node] = a[left];
            return;
        }
        int mid = left + (right - left) / 2;
        _build(a, node * 2, left, mid);
        _build(a, node * 2 + 1, mid + 1, right);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int pos, ll val) { return _update(1, 0, n - 1, pos, val ); }
    void _update(int node, int left, int right, int pos, ll val) {
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
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(int q_left, int q_right) { return _query(1, 0, n - 1, q_left, q_right); }
    ll _query(int node, int left, int right, int q_left, int q_right) {
        if(q_left > right || q_right < left) return INF;
        if(q_left <= left && right <= q_right) return tree[node];
        int mid = left + (right - left) / 2;
        return min(
            _query(node * 2, left, mid, q_left, q_right),
            _query(node * 2 + 1, mid + 1, right, q_left, q_right)
        );
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector p(n, 0LL);
    vector A(n, 0LL);
    vector B(n, 0LL);
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
        A[i] = p[i] + i;
        B[i] = p[i] - i;
    }
    auto seg_tree_a = SegTree(A);
    auto seg_tree_b = SegTree(B);
    for(int i = 0; i < q; i ++) {
        int op;
        cin >> op;
        if(op == 1) {
            ll k, x;
            cin >> k >> x;
            k -= 1;
            seg_tree_a.update(k, x + k);
            seg_tree_b.update(k, x - k);
        } else if(op == 2) {
            ll k;
            cin >> k;
            k -= 1;
            ll ans = min(
                seg_tree_a.query(k, n - 1) - k,
                seg_tree_b.query(0, k) + k
            );
            cout << ans << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}