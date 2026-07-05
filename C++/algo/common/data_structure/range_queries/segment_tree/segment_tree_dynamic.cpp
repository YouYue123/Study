#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTreeDynamic {
    struct Node {
        ll sum = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* root;
    ll L, R;
    SegTreeDynamic(ll L, ll R): L(L), R(R) {
        root = new Node();
    }

    void update(ll pos, ll val) { return _update(root, L, R, pos, val ); }
    void _update(Node* cur, ll left, ll right, ll pos, ll val) {
        if(left == right) {
            cur->sum = val;
            return;
        }
        ll mid = left + (right - left) / 2;
        if(pos <= mid) {
            if(!cur->left) cur->left = new Node();
            _update(cur->left, left, mid, pos, val);
        } else {
            if(!cur->right) cur->right = new Node();
            _update(cur->right, mid + 1, right, pos, val);
        }
        cur->sum = (cur->left ? cur->left->sum : 0) + (cur->right ? cur->right->sum : 0);
    }

    ll query(ll q_left, ll q_right) { return _query(root, L, R, q_left, q_right); }
    ll _query(Node* cur, ll left, ll right, ll q_left, ll q_right) {
        if(!cur || q_right < left || q_left > right) return 0LL;
        if(q_left <= left && q_right >= right) return cur->sum;
        ll mid = left + (right - left) / 2;
        return _query(cur->left, left, mid, q_left, q_right) + _query(cur->right, mid + 1, right, q_left, q_right);
    }
};