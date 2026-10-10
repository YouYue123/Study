#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Query {
    ll op;
    ll val_1;
    ll val_2;
};
struct Node {
    ll sum = 0;
    // max(sum(l, k)) for k in [l, r]
    ll pre = 0;
    // max(sum(k, r)) for k in [l, r]
    ll suf = 0;
};
struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(vector<ll>& a): n(a.size()) {
        tree.resize(4 * n);
        _build(a, 1, 0, n - 1);
    } 

    Node _merge(Node& left_node, Node& right_node) {
        auto ans = Node();
        ans.sum = left_node.sum + right_node.sum;
        ans.pre = max(left_node.pre, left_node.sum + right_node.pre);
        ans.suf = max(right_node.suf, left_node.suf + right_node.sum);
        return ans;
    }

    void _assign(int node, ll val) {
        tree[node].sum = val;
        tree[node].pre = val;
        tree[node].suf = val;
    }

    void _build(vector<ll>& a, int node, int left, int right) {
        if(left == right) {
            _assign(node, a[left]);
            return;
        }
        int mid = left + (right - left) / 2;
        _build(a, node * 2, left, mid);
        _build(a, node * 2 + 1, mid + 1, right);
        tree[node] = _merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(ll pos, ll val) { return _update(1, 0, n - 1, pos, val); }
    void _update(int node, int left, int right, ll pos, ll val) {
        if(left == right) {
            _assign(node, val);
            return;
        }
        int mid = left + (right - left) / 2;
        if(pos <= mid) {
            _update(node * 2, left, mid, pos, val);
        } else {
            _update(node * 2 + 1, mid + 1, right, pos, val);
        }
        tree[node] = _merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int q_left, int q_right) { return _query(1, 0, n - 1, q_left, q_right); }
    Node _query(int node, int left, int right, int q_left, int q_right) {
        if(left > q_right || right < q_left) return Node();
        if(q_left <= left && right <= q_right) return tree[node];
        int mid = left + (right - left) / 2;
        auto left_ans = _query(node * 2, left, mid, q_left, q_right);
        auto right_ans = _query(node * 2 + 1, mid + 1, right, q_left, q_right);
        return _merge(left_ans, right_ans);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    auto seg_tree = SegTree(x);
    vector<Query> queries(q);
    for(int i = 0; i < q; i ++) {
        cin >> queries[i].op >> queries[i].val_1 >> queries[i].val_2;
        if(queries[i].op == 1) {
            seg_tree.update(queries[i].val_1 - 1, queries[i].val_2);
        } else if(queries[i].op == 2) {
            auto ans = seg_tree.query(queries[i].val_1 - 1, queries[i].val_2 - 1);
            cout << max(ans.pre, 0LL) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}