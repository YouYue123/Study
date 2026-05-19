#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<vector<ll>> match_pos(n + 2);
    vector<vector<ll>> bad_pos(n + 2);

    for(int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            match_pos[a[i]].push_back(i);
        } else {
            bad_pos[a[i]].push_back(i);
            bad_pos[b[i]].push_back(i);
        }
    }

    vector<int> dp(n + 1, n);

    for(int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            int v = a[i] + 1;
            int nxt_m = n;
            auto it_m = lower_bound(match_pos[v].begin(), match_pos[v].end(), i + 1);
            if (it_m != match_pos[v].end()) nxt_m = *it_m;

            int nxt_b = n;
            auto it_b = lower_bound(bad_pos[v].begin(), bad_pos[v].end(), i + 1);
            if (it_b != bad_pos[v].end()) nxt_b = *it_b;

            if (nxt_b < nxt_m) {
                dp[i] = nxt_b;
            } else {
                if (nxt_m == n) {
                    dp[i] = n;
                } else {
                    dp[i] = dp[nxt_m];
                }
            }
        }
    }

    ll ans = 0;
    for(int L = 0; L < n; L++) {
        int nxt_m = n;
        auto it_m = lower_bound(match_pos[1].begin(), match_pos[1].end(), L);
        if (it_m != match_pos[1].end()) nxt_m = *it_m;

        int nxt_b = n;
        auto it_b = lower_bound(bad_pos[1].begin(), bad_pos[1].end(), L);
        if (it_b != bad_pos[1].end()) nxt_b = *it_b;

        int F_L = n;
        if (nxt_b < nxt_m) {
            F_L = nxt_b;
        } else {
            if (nxt_m == n) {
                F_L = n;
            } else {
                F_L = dp[nxt_m];
            }
        }
        ans += (F_L - L);
    }

    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}