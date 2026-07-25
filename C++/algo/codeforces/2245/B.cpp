#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, c;
    cin >> n >> c;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end(), less<>());
    for(int i = 0; i < n; i ++) a[i] -= c;
    for(int i = 0; i < n / 2; i ++) a[i] = max(a[i], 0LL);
    cout << accumulate(a.begin(), a.end(), 0LL) << endl;
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