#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector a(n, 0);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int left = 0, right = 0, ans = 0;
    ll cur = 0;
    while(right < n) {
        cur += a[right];
        while(cur > t) {
            cur -= a[left];
            left += 1;
        }
        ans = max(ans, right - left + 1);
        right += 1;
    }
    cout << ans << endl;
}