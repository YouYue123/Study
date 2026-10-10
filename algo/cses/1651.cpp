#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct BIT {
    vector<ll> tree;
    
    BIT(vector<ll>& arr) {
        tree.resize(arr.size() + 1);
        for(int i = 0; i < arr.size(); i ++) {
            update(i + 1, arr[i]);
        }
    }
    
    int lowbit(int x) { return x  & (-x); }

    void update(int idx, int val) {
        while(idx < tree.size()) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }

    ll query (int idx) {
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
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    vector diff(n, 0LL); 
    diff[0] = x[0];
    for(int i = 1; i < n; i ++) {
        diff[i] = x[i] - x[i - 1];
    }
    auto bit = BIT(diff);
    
    for(int i = 0; i < q; i ++) {
        int op;
        cin >> op;
        if(op == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            bit.update(a, u);
            bit.update(b + 1, -u);
        } else if(op == 2) {
            int k;
            cin >> k;
            cout << bit.query(k) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}