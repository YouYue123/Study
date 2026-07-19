#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree(int n_) : n(n_), tree(4 * n_, INF) {}

    void update(int pos, ll val) { return _update(1, 0, n - 1, pos, val); }
    void _update(int node, int left, int right, int pos, ll val) {
        if (left == right) {
            tree[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if (pos <= mid) {
            _update(node * 2, left, mid, pos, val); 
        } else {
            _update(node * 2 + 1, mid + 1, right, pos, val);
        }
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(int ql, int qr) { return _query(1, 0, n - 1, ql, qr); }
    ll _query(int node, int left, int right, int ql, int qr) {
        if (qr < left || right < ql) return INF;
        if (ql <= left && right <= qr) return tree[node];
        int mid = left + (right - left) / 2;
        return min(
            _query(node * 2, left, mid, ql, qr),
            _query(node * 2 + 1, mid + 1, right, ql, qr)
        );
    }
};

// (value, position) 集合，position 用 1-indexed；position 0 作为“不存在”的哨兵
set<pair<ll, ll>> occ;

ll find_next(ll pos, ll value) {
    auto it = occ.upper_bound({ value, pos });
    if (it == occ.end() || it->first != value) return INF;
    return it->second;
}

ll find_prev(ll pos, ll value) {
    auto it = occ.lower_bound({value, pos});
    if (it == occ.begin()) return 0;
    --it;
    if (it->first != value) return 0;
    return it->second;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> x(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];

    SegTree seg(n + 1);

    for (int i = 1; i <= n; i++) occ.insert({ x[i], i });

    for (int i = 1; i <= n; i++) {
        ll nxt = find_next(i, x[i]);
        seg.update(i, nxt);
    }

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            ll k, u;
            cin >> k >> u;

            ll v = x[k];
            // 当把位置 k 的值由旧值 v 修改为新值 u 时
            // 相当于在相同值构成的“链表”中删除一个节点，再插入一个新节点。需要维护这些受到影响的元素的nxt指针
            // 处理旧值 v 的剥离
            ll prev_node_v = find_prev(k, v);
            ll nxt_node_v = find_next(k, v);
            seg.update(prev_node_v, nxt_node_v);
            occ.erase({v, k});

            x[k] = u;

            // 处理新值 u 的接入
            ll prev_node_u = find_prev(k, u);
            seg.update(prev_node_u, k);
            ll nxt_node_u = find_next(k, u);
            seg.update(k, nxt_node_u);
            occ.insert({u, k});
        } else {
            int a, b;
            cin >> a >> b;
            ll mn = seg.query(a, b);
            cout << (mn <= b ? "NO" : "YES") << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}