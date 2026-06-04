#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector p(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> p[i];
    sort(p.begin(), p.end());
    int left = 0, right = n - 1;
    ll ans = 0;
    while(left < right) {
        if(p[right] + p[left] <= x) {
            right -= 1;
            left += 1;
        } else {
            right -= 1;
        }
        ans += 1;
    }
    
    if(left == right) ans += 1;
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}