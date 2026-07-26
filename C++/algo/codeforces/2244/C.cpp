#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int g = gcd(x, y);
    bool ok = true;
    for(int i = 0; i < n; i ++) {
        if((a[i] % g) != ((i + 1) % g)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}