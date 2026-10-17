#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    if(k > 2) {
        cout << 0 << endl;
        return;
    } else {
        // k == 1 or k == 2
        ll ans = a[0];
        for(int i = 0; i < n - 1; i ++) {
            for(int j = i + 1; j < n; j ++) {
                ll diff = abs(a[i] - a[j]);
                ans = min(ans, diff);
                if(k == 2) {
                    auto lower_it = lower_bound(a.begin(), a.end(), diff);
                    auto upper_it = upper_bound(a.begin(), a.end(), diff);
                    if(lower_it != a.end()) {
                        // == 
                        ans = min(ans, abs(*lower_it - diff));
                    }
                    if(lower_it != a.begin()) {
                        // <
                        lower_it -= 1;
                        ans = min(ans, abs(*lower_it - diff));
                    }
                    if(upper_it != a.end()) {
                        // >
                        ans = min(ans, abs(*upper_it - diff));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    
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