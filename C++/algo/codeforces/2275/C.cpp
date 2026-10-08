#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    unordered_map<ll, ll> dict;
    auto get_val = [&] (int i) {
        ll p = a[i], q = a[i + 2], s = a[i + 4];
        return p + q - s;
    };
    for(int i = 0; i < n; i ++) {
        if(i + 4 >= n) break;
        dict[get_val(i)] += 1;
        // cout << get_val(i) << " ";
    }
    // cout << endl;
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        if(i + 4 >= n) break;
        dict[get_val(i)] -= 1;
        ans += dict[get_val(i)];
        for(int j = i + 2; j <= i + 4; j += 2) {
            if(j + 4 >= n) break;
            if(get_val(j) == get_val(i)) {
                ans -= 1;
            }
        }
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