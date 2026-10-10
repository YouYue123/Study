#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 1e9 + 7;
struct BIT {
    vector<ll> tree;
    BIT(int N) {
        tree.assign(N + 1, 0LL);
    };
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int idx, ll val) {
        while(idx < tree.size()) {
            tree[idx] = (tree[idx] + val) % MOD;
            idx += lowbit(idx);
        }
    }  
    ll query(int idx) {
        ll ans = 0;
        while(idx > 0) {
            ans = (ans + tree[idx]) % MOD;
            idx -= lowbit(idx);
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<ll> sorted(a.begin(), a.end());
    sort(sorted.begin(), sorted.end());
    auto new_end = unique(sorted.begin(), sorted.end());
    sorted.erase(new_end, sorted.end());
    // for(auto& item : sorted) {
    //     cout << item << endl;
    // }
    auto get_rank = [&] (ll val) {
        auto it = lower_bound(sorted.begin(), sorted.end(), val);
        return it - sorted.begin() + 1;
    };

    ll ans = 0 ;
    auto bit = BIT(n);
    
    vector dp(n, 0LL);
    for(int i = 0; i < n; i ++) {
        int rank = get_rank(a[i]);
        // cout << "for: " << a[i] << " rank: " << rank << endl;
        dp[i] = (1 + bit.query(rank - 1)) % MOD;
        // for(int j = 0; j < i; j ++) {
        //     if(a[j] < a[i]) dp[i] += dp[j];
        // }
        bit.update(rank, dp[i]);
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}