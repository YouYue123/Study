#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct SegTree {
    struct Node {
        ll sum = 0LL;
        ll pre = 0LL;
        ll suf = 0LL;
        ll best = 0LL;
    };
    int n;
    vector<Node> tree;
    SegTree(vector<ll>& a): n(a.size()) {
        tree.resize(4 * n);
        _build(a, 1, 0, n - 1);
    }

    void _assign(int node, ll val) {
        tree[node].sum = val;
        tree[node].pre = val;
        tree[node].suf = val;
        tree[node].best = val;
    }

    Node _merge(Node left, Node right) {
        auto ans = Node();
        ans.sum = left.sum + right.sum;
        ans.pre = max(left.pre, left.sum + right.pre);
        ans.suf = max(right.suf, right.sum + left.suf);
        ans.best = max({
            left.best, 
            right.best,
            left.suf + right.pre,
        });
        return ans;
    }
    void _build(vector<ll>& a, int node, int left, int right) {
        if(left == right) {
            _assign(node, a[left]);
            return;
        }
        int mid =  left + (right - left) / 2;
        _build(a, node * 2, left , mid);
        _build(a, node * 2 + 1, mid + 1, right);
        tree[node] = _merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int pos, ll val) { return _update(1, 0, n - 1, pos, val); };
    void _update(int node, int left, int right, int pos, ll val) {
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
        return _merge(
            _query(node * 2, left, mid, q_left, q_right),
            _query(node * 2 + 1, mid + 1, right, q_left, q_right)
        );
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    auto seg_tree = SegTree(x);
    for(int i = 0; i < m ; i ++) {
        ll k, a;
        cin >> k >> a;
        k -= 1;
        seg_tree.update(k, a);
        cout << max(0LL, seg_tree.query(0, n - 1).best)<< endl;
        // x[k] = a;
        // ll ans = 0;
        // ll prev = 0;
        // for(int i = 0; i < n; i ++) {
        //     prev = max(x[i], prev + x[i]);
        //     ans = max(ans, prev);
        // }
        // cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}