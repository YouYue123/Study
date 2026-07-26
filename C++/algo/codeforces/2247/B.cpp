#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    if(k > m) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i ++) {
        if(i % k != 0) {
            cout << 1 << " ";
        } else {
            cout << m - k + 1 << " ";
        }
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