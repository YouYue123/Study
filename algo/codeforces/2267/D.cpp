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
    vector p(n + 1, 0LL);
    for(int i = 0; i < n; i ++) {
        int idx = i + 1;
        p[a[i]] = (i + 1) % 2;
    }
    // 1 5 2 3 6 4
    // 1 0 1 0 1 0
    bool ok = true;
    int left = 1;
    if(n % 2 == 1) {
        if(p[1] % 2 == 0) {
            ok = false;
        }
        left = 2;
    }
    if(ok) {
        while(left < n) {
            if(p[left] + p[left + 1] != 1) {
                ok = false;
                break;
            }
            left += 2;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
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