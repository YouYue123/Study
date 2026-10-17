#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct Item {
    ll num;
    ll cnt;
    ll get_score() {
        return num * cnt;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n;
    cin >> n;
    vector a(n, 0);
    for(int i = 0; i < n; i ++) cin >> a[i];
    map<ll, ll> dict;
    for(int i = 0; i < n; i ++) dict[a[i]] += 1;
    vector<Item> new_a;
    for(auto& [num, cnt] : dict) new_a.emplace_back(num, cnt);
    vector memo(new_a.size(), vector(2, -1LL));
    auto dfs = [&] (this auto&& dfs, ll i, bool is_prev_selected) -> ll {
        if(i == new_a.size()) return 0LL;
        if(memo[i][is_prev_selected] != -1) return memo[i][is_prev_selected];
        ll ans = dfs(i + 1, false);
        if(!is_prev_selected || new_a[i - 1].num < new_a[i].num - 1) {
            ans = max(ans, new_a[i].get_score() + dfs(i + 1, true));
        }
        return memo[i][is_prev_selected] = ans;
    };

    cout << dfs(0, false) << endl;
}