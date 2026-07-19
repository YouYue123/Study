#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct BIT {
    vector<int> tree;
    BIT(int n){
        tree.assign(n + 1, 0);
    }
    int lowbit(int i) {
        return i & (-i);
    }
    void update(int idx, int delta) {
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += lowbit(idx);
        }
    }
    int query(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx); 
        }
        return ans;
    }
};

struct Query {
    int  left;
    int  right;
    int idx;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    vector<ll> uniq_vals = x;
    sort(uniq_vals.begin(), uniq_vals.end());
    uniq_vals.erase(unique(uniq_vals.begin(), uniq_vals.end()), uniq_vals.end());
    vector compressed_x(n, 0);
    for(int i = 0; i < n; i ++) {
        compressed_x[i] = lower_bound(uniq_vals.begin(), uniq_vals.end(), x[i]) - uniq_vals.begin();
    }

    vector<Query> queries(q);
    for(int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a, b, i};
    }

    sort(queries.begin(), queries.end(), [&] (auto& a, auto& b) {
        return a.right < b.right;
    });

    auto bit = BIT(n);
    vector last_pos(uniq_vals.size(), -1);
    vector<int> ans(q);

    int cur_idx = 0;
    for(auto& query : queries) {
        while(cur_idx < query.right) {
            int compressed_val = compressed_x[cur_idx];
            if(last_pos[compressed_val] != -1) bit.update(last_pos[compressed_val], -1);
            bit.update(cur_idx + 1, 1);
            last_pos[compressed_val] = cur_idx + 1;
            cur_idx += 1;
        }
        ans[query.idx] = bit.query(query.right) - bit.query(query.left - 1);
    }

    for(int i = 0; i < q; i ++) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
