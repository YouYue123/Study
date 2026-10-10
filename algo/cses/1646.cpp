#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, q;
    cin >> n >> q;
    vector x(n + 1, 0LL);
    for(int i = 1; i <= n; i ++)  cin >> x[i];
    vector pre_sum(n + 2, 0LL);
    for(int i = 1; i <= n; i ++) {
        pre_sum[i + 1] = pre_sum[i] + x[i];
    }
    for(int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        cout << pre_sum[b + 1] - pre_sum[a] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}