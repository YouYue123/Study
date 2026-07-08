#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct SegTree {
    struct Node {
        ll max;
        vector<ll> vis;
    };
    int n;
    vector<Node> tree;
    
    SegTree(vector<ll>& a): n(a.size()) {
        tree.resize(4 * n);
        _build(a, 1, 0, n - 1);
    }
    Node _merge (Node& left, Node& right) {
        auto ans = Node();
        ans.max = max(left.max, right.max);
        ans.vis = left.vis;
        auto it = upper_bound(right.vis.begin(), right.vis.end(), left.max);
        ans.vis.insert(ans.vis.end(), it, right.vis.end());
        return ans;
    }
    void _build(vector<ll>& a, int node, int left, int right) {
        if(left == right) {
            tree[node].max = a[left];
            tree[node].vis.push_back(a[left]);
            return;
        }
        int mid = left + (right - left) / 2;
        _build(a, node * 2, left, mid);
        _build(a, node * 2 + 1, mid + 1, right);
        tree[node] = _merge(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int q_left, int q_right)  {  
        ll cur_max = -INF;
        return _query(1, 0, n - 1, q_left, q_right, cur_max);
    } 
    int _query(int node, int left, int right, int q_left, int q_right, ll& cur_max) {
        if(left > q_right || right < q_left) return 0;
        if(q_left <= left && right <= q_right) {
            auto it = upper_bound(tree[node].vis.begin(), tree[node].vis.end(), cur_max);
            int cnt = tree[node].vis.end() - it;
            cur_max = max(cur_max, tree[node].max);
            return cnt;
        }
        int mid = left + (right - left) / 2;
        int ans = 0;
        ans += _query(node * 2, left, mid, q_left, q_right, cur_max);
        ans += _query(node * 2 + 1, mid + 1, right, q_left, q_right, cur_max);
        return ans;
    }

};

void solve() {
    int n, q;
    cin >> n >> q;
    vector h(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> h[i];
    auto seg_tree = SegTree(h);
    for(int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        cout <<  seg_tree.query(a, b) << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}