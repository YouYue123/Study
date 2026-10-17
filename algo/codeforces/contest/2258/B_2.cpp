#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector a(n, 0LL);
    vector freq(m + 1, 0);
    vector presum(m + 1, 0);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        freq[a[i]] += 1;
    }
    for(int num = 1; num <= m; num += 1) presum[num] = presum[num - 1] + freq[num];
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    
    for(int k = 1; k <= m; k ++) {
        ll ans = 0;
        if(k > 30 || (1LL << k) >= m) {
            ans = sum;
        } else {
            ll cap = (1LL << k);
            for(ll x = 1; x <= m / cap + 1; x ++) {
                ll cur = 0;
                for(int cnt = 1; cnt < cap && (x * cnt) <= m; cnt ++) {
                    cur += n - presum[x * cnt - 1];
                }
                if(x * cap <= m) {
                    cur += freq[x * cap];
                }
                ans = max(ans, cur);
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}