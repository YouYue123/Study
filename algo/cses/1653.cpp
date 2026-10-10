#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, x;
    cin >> n >> x;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    
    ll final_state = (1 << n) - 1;
    // { min_box, last_cap }
    vector<pair<int, ll>> memo(1 << n, {-1, -1});
    auto dfs = [&] (auto& dfs, ll state) -> pair<int, ll> {
        if(final_state == state) return { 1, 0 };
        if(memo[state].first != -1) return memo[state];
        pair<int, ll> ans = { n + 1, 0 };
        for(int i = 0; i < n; i ++) {
            if(state & (1 << i)) continue;
            ll nxt_state = state | (1 << i); 
            auto [ cnt, cap ] = dfs(dfs, nxt_state);
            if(cap + a[i]  <= x) {
                if(make_pair(cnt, cap + a[i] ) < ans) {
                    ans = make_pair(cnt, cap + a[i] );
                }
            } else {
                if(make_pair(cnt + 1, a[i]) < ans)  {
                    ans = make_pair(cnt + 1, a[i]);
                }
            }
        }
        return memo[state] = ans;
    };

    cout << dfs(dfs, 0).first << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}