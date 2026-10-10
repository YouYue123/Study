#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, 0LL);
    vector cnt(m + 1, 0);
    vector presum(m + 1, 0);
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    for(int num = 1; num <= m; num += 1) presum[num] = presum[num - 1] + cnt[num];
    for(int num = 1; num <= m; num += 1) {
        ans = max(
            ans,
            presum[m] - presum[num - 1] + (num * 2 <= m ? cnt[num * 2] : 0)
        );
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