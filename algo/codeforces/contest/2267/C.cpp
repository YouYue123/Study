#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<ll> prime_factors;
    for(ll p = 2; p * p <= x; p ++) {
        if(x % p == 0) {
            prime_factors.push_back(p);
            while(x % p == 0) x /= p;
        }
    }
    if(x > 1) prime_factors.push_back(x);
    unordered_map<ll, ll> dict;
    for(int num : a) {
        for(ll f : prime_factors) {
            if(num % f == 0) {
                dict[f] += num;
            }
        }
    }
    ll ans = 0;
    for(auto& [f, cnt] : dict) {
        ans = max(ans, cnt);
    }
    cout << ans << endl;
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