#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll constexpr MAX_N = 200001;
ll constexpr LOG = 30;
void solve() {
    int n, q;
    cin >> n >> q;
    vector g(n + 1, 0LL);
    for(int i = 1; i <= n; i ++) cin >> g[i];
    int up[LOG][MAX_N];
    memset(up, 0, sizeof(up));
    for(int i = 1; i <= n; i ++) up[0][i] = g[i];
    for(int j = 1; j < LOG; j ++) {
        for(int i = 1; i <= n; i ++) {
            int prev = up[j - 1][i];
            up[j][i] = up[j - 1][prev];
        }
    }

    for(int i = 0; i < q; i ++) {
        int x, k;
        cin >> x >> k;
        for(int j = 0; j < LOG; j ++) {
            if(k & (1 << j)) {
                x = up[j][x];
            }
        }
        cout << x << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}