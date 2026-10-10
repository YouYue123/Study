#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct SegmentTree {
    int n;
    vector<ll> tree;
    SegmentTree(vector<ll>& a): n(a.size()) {
        tree.assign(4 * n, 0LL);
        build(a, 1, 0, n - 1);
    }

    void build (vector<ll>& a, int node, int left, int right) {
        if(left == right) {
            tree[node] = a[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build(a, node * 2, left, mid);
        build(a, node * 2 + 1, mid + 1, right);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
    
    void update(int pos, int val) {
        return update(1, 0, n - 1, pos, val);
    }
    void update(int node, int left, int right, int pos, int val) {
        if(left == right) {
            tree[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if(pos <= mid) {
            update(node * 2, left, mid, pos, val);
        } else {
            update(node * 2 + 1, mid + 1, right, pos, val);
        }
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(int q_left, int q_right) {
        return query(1, 0, n - 1, q_left, q_right);
    }
    ll query (int node, int left, int right, int q_left, int q_right) {
        if(left > q_right || right < q_left) return INF;
        if(q_left <= left && q_right >= right) return tree[node];
        int mid = left + (right - left) / 2;
        return min(
            query(node * 2, left, mid, q_left, q_right),
            query(node * 2 + 1, mid + 1, right, q_left, q_right)
        );
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    auto seg_tree = SegmentTree(x);
    for(int i = 0; i < q; i ++) {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1) {
            seg_tree.update(a - 1, b);
        } else if(op == 2) {
            cout << seg_tree.query(a - 1, b - 1) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}