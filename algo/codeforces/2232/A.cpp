#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    int left = 0, right = n - 1;
    int t = a[n / 2];
    ll ans = 0;
    while(left < right) {
        if(a[left] != t || a[right] != t) {
            left += 1;
            right -= 1;
            ans += 1;
        } else if(a[left] == t) {
            left += 1;
        } else if(a[right] == t) {
            right -= 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}