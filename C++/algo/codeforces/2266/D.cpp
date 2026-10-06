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
    set<ll> invar;
    for(int i = 0; i < n; i ++) {
        invar.insert(a[i] - i);
    }
    // 5 5 5 9 8
    // 5 4 3 6
    int ans = 0, cur = -1, cnt = 0;
    for(int num : invar) {
        if(num != cur + 1) {
            cnt = 1;
        } else {
            cnt += 1;
        }
        cur = num;
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