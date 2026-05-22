#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
// vector<int> memo
void solve()
{
    int x;
    cin >> x;
    vector<ll> candidate;
    unordered_map<int, bool> dp;
    int mx = 11 * 111 - 111 - 11;
    if(x > mx) {
        cout << "YES" << endl;
        return;
    }
    vector memo(mx, -1);
    auto dfs = [&] (this auto&& dfs, int num) -> bool {
        if(num < 11) return false;
        if(num == 11 || num == 111) return true;
        if(memo[num] != -1) return memo[num];
        return memo[num] = dfs(num - 11) || dfs(num - 111);
    };

    cout << (dfs(x) ? "YES" : "NO") << endl;
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