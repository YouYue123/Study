#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    // cout << n << k << endl;
    string s;
    cin >> s;
    if(n < 2 * k) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    int left = 0, right = n - 1;
    for(int i = 0; i < k; i ++) {
        if(s[i] != 'R') ans += 1;
    }
    for(int i = n - 1; i > n - 1 - k; i --) {
        if(s[i] != 'L') ans += 1;
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