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
    int cnt_1 = 0, cnt_0 = 0;
    for(int i = 0 ; i < n; i ++) {
        if(a[i] == 1) cnt_1 += 1;
        else cnt_0 += 1;
    }
    bool ok = cnt_1 >= cnt_0;
    cout << (ok ? "Bessie" : "Elsie") << endl;
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