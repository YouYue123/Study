#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll target = ceil(n, k) * k;
    ll ans = ceil(target, n);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}