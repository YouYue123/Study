#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct SegTree {
    // Rec: val 是记录值(区间内递增的"新纪录"),
    //      cumLen 是"从头到本记录为止"的累计长度,
    //      cumSum 是"从头到本记录为止"的 val*len 累计和
    struct Rec {
        ll val;
        ll cum_len;
        ll cum_sum;
    };
    struct Node {
        ll max;
        vector<Rec> rec;
    };
    int n;
    vector<Node> tree;
    SegTree(vector<ll>& a): n(a.size()) {
        tree.resize(n * 4);
        _build(a, 1, 0, n - 1);
    }

    Node _merge(Node& left, Node& right) {
        auto ans = Node();
        ans.max = max(left.max, right.max);

        auto it = upper_bound(
            right.rec.begin(), 
            right.rec.end(), 
            left.max,
            [&] (ll v, const Rec& r) { return v < r.val; }
        );
        int idx = it - right.rec.begin();
        ll left_prev_cumLen = (left.rec.size() >= 2) ? left.rec[left.rec.size()-2].cum_len : 0;
        ll left_prev_cumSum = (left.rec.size() >= 2) ? left.rec[left.rec.size()-2].cum_sum : 0;
        ll right_dominated_len = (idx == 0) ? 0 : right.rec[idx-1].cum_len;
        ans.rec.reserve(left.rec.size() + (right.rec.size() - idx));
        // 复制 left 除最后一项外的部分,累计值不变
        for (int i = 0; i + 1 < (int)left.rec.size(); i++) ans.rec.push_back(left.rec[i]);
        // left 最后一项:长度并入被 right 吃掉的那部分
        ll last_val = left.rec.back().val;
        ll last_len = (left.rec.back().cum_len - left_prev_cumLen) + right_dominated_len;
        ll new_cumLen = left_prev_cumLen + last_len;
        ll new_cumSum = left_prev_cumSum + last_val * last_len;
        ans.rec.push_back({last_val, new_cumLen, new_cumSum});

        // 拼接 right 剩余(未被吃掉)的部分
        ll base_len = new_cumLen;
        ll base_sum = new_cumSum;
        for (int i = idx; i < (int)right.rec.size(); i++) {
            ll prevCum = (i == idx) ? right_dominated_len : right.rec[i-1].cum_len;
            ll len_i = right.rec[i].cum_len - prevCum;
            base_len += len_i;
            base_sum += right.rec[i].val * len_i;
            ans.rec.push_back({right.rec[i].val, base_len, base_sum});
        }
        return ans;
    }
    void _build(vector<ll>& a, int node, int left, int right) {
        if(left == right) {
            tree[node].max = a[left];
            tree[node].rec = { {a[left], 1, a[left]} };
            return;
        }
        int mid = left + (right - left) / 2;
        _build(a, node * 2, left, mid);
        _build(a, node * 2 + 1, mid + 1, right);
        tree[node] = _merge(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(int q_left, int q_right) {
        ll cur_max = -INF;
        return _query(1, 0, n - 1, q_left, q_right, cur_max);
    }
    ll _query(int node, int left, int right, int q_left, int q_right, ll& cur_max) {
        if(left > q_right || right < q_left) return 0;
        if(q_left <= left && right <= q_right) {
            auto& nd = tree[node];
            int idx = (int)(upper_bound(nd.rec.begin(), nd.rec.end(), cur_max,
                            [](ll v, const Rec& rc){ return v < rc.val; }) - nd.rec.begin());
            ll dominated_len = (idx == 0) ? 0 : nd.rec[idx-1].cum_len;
            ll total_sum = nd.rec.empty() ? 0 : nd.rec.back().cum_sum;
            ll prev_sum = (idx == 0) ? 0 : nd.rec[idx-1].cum_sum;
            ll contrib = cur_max * dominated_len + (total_sum - prev_sum);
            cur_max = max(cur_max, nd.max);
            return contrib;
        }
        int mid = left + (right - left) / 2;
        return _query(node * 2, left, mid , q_left, q_right, cur_max) + 
               _query(node * 2 + 1, mid + 1,  right, q_left, q_right, cur_max);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    vector<ll> pre(n + 1, 0);
    for(int i = 0; i < n; i ++) pre[i + 1] = pre[i] + x[i];

    auto seg_tree = SegTree(x);
    for(int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        ll pre_max_sum = seg_tree.query(a, b);
        ll range_sum = pre[b + 1] - pre[a];
        cout << pre_max_sum - range_sum << endl;
        // ll ans = 0;
        // ll cur = x[a];
        // for(int i = a + 1; i <= b; i ++) {
        //     ans += max(0LL, cur - x[i]);
        //     cur = max(cur, x[i]);
        // }
        // cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}