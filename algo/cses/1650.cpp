#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, q;
    cin >> n >> q;
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    vector presum(n + 1, 0LL);
    for(int i = 0; i < n; i ++) {
        presum[i + 1] = presum[i] ^ x[i];
    }
    for(int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        cout << (presum[b + 1] ^ presum[a]) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}