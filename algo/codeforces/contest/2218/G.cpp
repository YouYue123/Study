#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 676767677;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector b(n, 0LL);
    // cnt[t] -> exact ppl sat at time t
    vector cnt(m, 0LL);
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
        cnt[b[i]] += 1;
    }
    // c[t] -> total ppl sat before time t
    vector c(m, 0LL);
    // c[0] = cnt[0];
    for(int t = 1; t < m; t ++) {
        c[t] = c[t - 1] + cnt[t - 1];
        // cout << c[t] << " ";
    }
    // cout << endl;
    ll ans = 1;
    for(int i = 0; i < n; i ++) {
        ll cur = b[i];
        // cout << "calc idx: " << i << " cur: " << cur << endl;

        if(cur == 0) continue;
        ll min_neighbour = INF;
        if(i > 0) min_neighbour = min(min_neighbour, b[i - 1]);
        if(i < n - 1) min_neighbour = min(min_neighbour, b[i + 1]);
        // cout << "min_neighbour: " << min_neighbour << endl;
        if(min_neighbour >= cur) {
            // cout << "not valid!!" << endl;
            cout << 0 << endl;
            return;
        }
        if(min_neighbour + 1 == cur) {
            // Met cond 1, wait cond 2
            // could choose between [1, c[cur - 1]]
            // cur is for sure >= 1
            // cout << c[cur] << endl;
            ans = (ans * c[cur]) % MOD;
        } else {
            // Met cond 2, wait cond 1
            // could choose between ( c[cur - 2] + 1, c[cur - 1] ]
            // cur is for sure >= 2
            ans = (ans * (c[cur]  - (c[cur - 1] + 1) + 1) % MOD) % MOD;
        }
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