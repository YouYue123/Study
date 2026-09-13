#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, 0), b(m, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    cout << "here" << endl;
    cout << ((a[0] + n >= b[0] + m) ? 1 : 2) << endl;
}
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << T <<endl;
        solve();
    }
    return 0;
}