#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

u128 diff(u128 b, ll a) {
    return abs((ll)b - a);
}

void solve()
{
    ll a, n;
    cin >> a >> n;
    vector<ll> d(n);
    for(int i = 0; i < n; i ++) cin >> d[i];
    int d_min = d.front(), d_max = d.back();
    if(d_min == 0 && d_max == 0) {
        cout << a << endl;
        return;
    }
    u128 b = 0, ans = -1;
    string a_s = to_string(a);
    int a_len = a_s.size();
    if(a_len > 1) {
        for(int i = 0; i < a_len - 1; i ++) {
            b = b * 10 + d_max;
        }
        ans = min(ans, diff(b, a));
    }
    
    b = 0;
    if(d_min == 0 && n > 1) {
        b = d[1];
    }
    for(int i = 0; i < a_len; i ++) {
        b = b* 10 + d_min;
    }
    ans = min(ans, diff(b, a));

    auto dfs = [&] (this auto&& dfs, u128 cur_b, int len, bool is_larger, bool is_smaller) -> void {
        if(len == a_len) {
            ans = min(ans, diff(cur_b, a));
            return;
        }
        
        if(is_larger) {
            while(len < a_len) {
                cur_b = cur_b * 10 + d_min;
                len += 1;
            }
            ans = min(ans, diff(cur_b, a));
            return;
        }

        if(is_smaller) {
            while(len < a_len) {
                cur_b = cur_b * 10 + d_max;
                len += 1;
            }
            ans = min(ans, diff(cur_b, a));
            return;
        }
        
        for(int i = 0; i < n; i ++) {
            auto nxt_b = cur_b * 10 + d[i];
            if(a_s[len] - '0' == d[i]) {
                dfs(nxt_b, len + 1, false, false);
            } else if(a_s[len] - '0' < d[i]) {
                dfs(nxt_b, len + 1, true, false);
            } else {
                dfs(nxt_b, len + 1, false, true);
            }
        }
    };

    dfs(0, 0, false, false);

    cout << (ll)ans << endl;
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