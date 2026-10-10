#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct BIT {
    vector<ll> tree;
    BIT(int n) {
        tree.resize(n + 1);
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void update (int idx, ll delta) {
        while(idx < tree.size()) {
            tree[idx] += delta;
            idx += lowbit(idx);
        }
    }
    ll query(int idx) {
        ll ans = 0;
        while(idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector x(n + 1, 0LL);
    for(int i = 1; i <= n; i ++) cin >> x[i];
    auto bit = BIT(n + 1);
    for(int i = 1; i <= n; i ++) {
        bit.update(i, x[i]);
    }

    for(int i = 0; i < q; i ++) {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1) {
            ll delta = b - x[a];
            bit.update(a, delta);
            x[a] = b;
        } else {
            cout << bit.query(b) - bit.query(a - 1) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}