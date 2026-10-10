
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll sum = 0;
    // max(sum(l, k)) for k in [l, r]
    ll pre = 0;
    // max(sum(k, r)) for k in [l, r]
    ll suf = 0;
    // max sub arr sum 
    ll best = 0;
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
        ans.best = max({
            left_node.best,
            right_node.best,
            left_node.suf + right_node.pre
        });
        return ans;
    }

    void _assign(int node, ll val) {
        tree[node].sum = val;
        tree[node].pre = val;
        tree[node].suf = val;
        tree[node].best = val;
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