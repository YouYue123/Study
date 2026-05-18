#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
using i128 = unsigned __int128;

i128 diff(i128 b, ll a){
    return abs((ll)b - a);
}

void solve()
{
    ll a, n;
    cin >> a >> n;
    // cout << "for: " << "a: " << a << " n: " << n << endl;
    vector<ll> d(n);
    for(int i = 0; i < n; i ++) cin >> d[i];
    int d_min = d.front(), d_max = d.back();
    if(d_min == 0 && d_max == 0) {
        cout << a << endl;
        return;
    }
    string a_s = to_string(a);
    ll a_len = a_s.size();
    i128 cur_b = 0, ans = -1;

    if(a_len > 1) {
        // 1 digit shorter
        for(int i = 0; i < a_len - 1; i ++) {
            cur_b = cur_b * 10 + d_max;
        }
        ans = min(ans, diff(cur_b, a));
        // cout << "1 digit shorter: " << (ll)cur_b << endl;
    }


    // 1 digit longer
    cur_b = d_min == 0 ? d_max : d_min;
    for(int i = 0; i < a_len; i ++) {
        cur_b = cur_b * 10 + d_min;
    }
    ans = min(ans, diff(cur_b, a));
    // cout << "1 digit longer ans: " << (ll)cur_b<< endl;


    // exact match
    auto dfs = [&] (this auto&& dfs, i128 b, int len, bool is_larger, bool is_smaller) {
        if(len == a_len) {
            // cout << len << endl;
            // cout << "same len: " << (ll)b<< endl;
            ans = min(ans, diff(b, a));
            return;
        }
        if(is_larger) {
            while(len < a_len) {
                b = b * 10 + d_min;
                len += 1;
            }
            // cout << "is_larger: " << (ll)b<< endl;
            ans = min(ans, diff(b, a));
            return;
        }

        if(is_smaller) {
            while(len < a_len) {
                b = b * 10 + d_max;
                len += 1;
            }
            // cout << "is_smaller: " << (ll)b<< endl;
            ans = min(ans, diff(b, a));
            return;
        }

        for(int i = 0; i < n; i ++) {
            i128 nxt_b = b * 10 + d[i];
            if(d[i] == (a_s[len] - '0')) {
                dfs(nxt_b, len + 1, false, false);
            } else if(d[i] < (a_s[len] - '0')) {
                dfs(nxt_b, len + 1, false, true);
            } else {
                dfs(nxt_b, len + 1, true, false);
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