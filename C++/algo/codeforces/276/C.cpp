#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector diff(n + 1, 0LL);
    for(int i = 0; i < q; i ++) {
        int l, r;
        cin >> l >> r;
        l -= 1;
        r -= 1;
        diff[l] += 1;
        diff[r + 1] -= 1;
    }
    vector freq(n, 0LL);
    int cur = 0;
    for(int i = 0 ; i < n; i ++) {
        cur += diff[i];
        freq[i] = cur;
    }
    sort(freq.begin(), freq.end(), greater<>());
    sort(a.begin(), a.end(), greater<>());
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        ans += freq[i] * a[i];
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}