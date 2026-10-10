#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll a, n;
    cin >> a >> n;
    vector d(n, 0);
    for(int i = 0; i < n; i ++) cin >> d[i];
    // cout << d.size() << endl;
    int d_min = d.front(), d_max = d[d.size() - 1];
    // cout << d_min << " " << d_max << endl;
    auto a_s = to_string(a);
    auto a_len = a_s.size();
    ll ans = INF;
    // 1 digit less
    if(a_len > 1) {
        ll cur = 0;
        for(int i = 0; i < a_len - 1; i ++) {
            cur = cur * 10 + d_max;
        }
        // cout << "1 digit less: " << cur << endl;
        ans = min(ans, abs(cur - a));
    }

    // 1 digit more
    if(d_min == 0) {
        if(d.size() > 1) {
            ll cur = d[1];
            for(int i = 0; i < a_len; i ++) {
                cur = cur * 10 + d_min;
            }
            ans = min(ans, abs(cur - a));
        }
    } else {
        ll cur = 0;
        for(int i = 0; i < a_len + 1; i ++) {
            cur = cur * 10 + d_min;
        }
        ans = min(ans, abs(cur - a));
    }

    auto dfs = [&] (this auto&& dfs, ll cur, int len, bool is_larger, bool is_smaller) {
        if(len == a_len) {
            ans = min(ans, abs(cur - a)); 
            return;
        }

        if(is_larger) {
            while(len < a_len) {
                cur = cur * 10 + d_min;
                len += 1;
            }
            ans = min(ans, abs(cur - a)); 
            return;
        }

        if(is_smaller) {
            while(len < a_len) {
                cur = cur * 10 + d_max;
                len += 1;
            }
            ans = min(ans, abs(cur - a)); 
            return;
        }
        int cur_a = a_s[len] - '0';
        for(int cand : d) {
            ll nxt = cur * 10 + cand;
            if(cand == cur_a) {
                dfs(nxt, len + 1, false, false);
            } else if(cand < cur_a) {
                dfs(nxt, len + 1, false, true);
            } else {
                dfs(nxt, len + 1, true, false);
            }
        }
    };

    dfs(0, 0, false, false);

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