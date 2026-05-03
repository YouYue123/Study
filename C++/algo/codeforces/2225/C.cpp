#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    auto get_vertical_cost = [&] (int idx) {
        return s1[idx] == s2[idx] ? 0 : 1;
    };
    auto get_horizontal_cost = [&] (int idx) {
        int row_1_cost = s1[idx] == s1[idx + 1]  ? 0 : 1;
        int row_2_cost =  s2[idx] == s2[idx + 1] ? 0 : 1;
        return row_1_cost + row_2_cost;
    };
    vector memo(n + 1, -1LL);
    auto dfs = [&] (this auto&& dfs, int i) -> ll {
        if(i == n) return 0LL;
        if(memo[i] != -1LL) return memo[i];
        ll ans = dfs(i + 1) + get_vertical_cost(i);
        if(i + 1 < n) {
            ans = min(
                ans,
                dfs(i + 2) + get_horizontal_cost(i)
            );
        }
        return memo[i] = ans;
    };
    cout << dfs(0) << endl;
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