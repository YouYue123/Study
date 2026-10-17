#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    ll x;
    ll h;
    ll get_left() {
        return x - h;
    }
    ll get_right() {
        return x + h;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<Item> items(n);
    for(int i = 0; i < n; i ++) {
        cin >> items[i].x >> items[i].h;
    }

    vector memo(n, vector(2, -1LL));
    auto dfs = [&] (this auto&& dfs, int i, int prev_dir) -> ll {
        if(i == n - 1) return 1LL;
        if(memo[i][prev_dir] != -1) return memo[i][prev_dir];
        ll cur_right = 0;
        if(prev_dir == 0) {
            // fell right
            cur_right = i > 0 ? items[i - 1].get_right() : -INF;
        } else {
            // stand or fell left
            cur_right = i > 0 ? items[i - 1].x : -INF;
        }
        // stand
        ll ans = dfs(i + 1, 1);
        if(cur_right < items[i].get_left()) {
            // fell left
            ans = max(ans, 1 + dfs(i + 1, 1));
        } else if(items[i].get_right() < items[i + 1].x) {
            // fell right;
            ans = max(ans, 1 + dfs(i + 1, 0));
        }
        return memo[i][prev_dir] = ans;
    };

    cout << dfs(0, 1) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}