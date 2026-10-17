#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector w_dict(26, false);
    for(int i = 0; i < n; i ++) {
        string w;
        cin >> w;
        w_dict[w[0] - 'a'] = true;
    }
    bool ok = true;
    for(int i = 0; i < m; i ++) {
        string a;
        cin >> a;
        // cout << a << endl;
        for(char c : a) {
            if(!w_dict[c - 'A']) {
                ok = false;
            }
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