#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Movie {
    ll start_time;
    ll end_time;
    // bool operator < (const Movie& other) const {
    //     return end_time 
    // }
};
void solve()
{
    int n;
    cin >> n;
    vector<Movie> movies(n);
    for(int i = 0; i < n; i ++) {
        cin >> movies[i].start_time >> movies[i].end_time;
    }
    sort(movies.begin(), movies.end(), [&] (auto& a, auto& b) {
        return a.end_time < b.end_time;
    });
    ll ans = 0, cur_end = 0;
    for(auto& m : movies) {
        if(m.start_time >= cur_end) {
            cur_end = m.end_time;
            ans += 1;
        }
    }
    cout << ans << endl;
    // vector memo(n, -1);
    // auto dfs  = [&] (this auto&& dfs, int i) {
    //     if(i == n) return 0;
    //     if(memo[i] != -1) return memo[i];
    //     cout << "for: " << movies[i].start_time << " - " << movies[i].end_time << endl;
    //     auto cur = movies[i];
    //     auto it = lower_bound(movies.begin(), movies.end(), movies[i], [&] (auto& a, auto& b) {
    //         return a.start_time < b.end_time;
    //     });
    //     if(it != movies.end()) cout << "find: " << it->start_time << " - " << it->end_time << endl;
    //     int nxt_idx = it - movies.begin();
    //     // cout << "nxt_idx: " << nxt_idx << endl;
    //     int ans = max(dfs(i + 1), 1 + dfs(nxt_idx));
    //     return memo[i] = ans;
    // };
    // vector memo(n + 1, -1);
    // memo[n] = 0;
    // for(int i = n - 1; i >= 0; i --) {
    //     auto it = lower_bound(movies.begin(), movies.end(), movies[i], [&] (auto& a, auto& b) {
    //         return a.start_time < b.end_time;
    //     });
    //     memo[i] = max(memo[i + 1], 1 + memo[it - movies.begin()]);
    // }

    // cout << memo[0] << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}