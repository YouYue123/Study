#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int x;
    cin >> x;
    vector<ll> candidate;
    unordered_map<int, bool> dp;
    for(int i = 1; i <= 9; i ++) {
        candidate.push_back(i * 10 + 1);
    }
    unordered_map<int, bool> memo;
    auto dfs = [&] (this auto&& dfs, int num) -> bool {
        if(num == 0) return true;
        if(num < 0) return false;
        if(memo.contains(num)) return memo[num];
        bool ans = false;
        for(auto& cand : candidate) {
            if(dfs(num - cand)) {
                ans = true;
                break;
            }
        }
        return memo[num] = ans;
    };

    cout << (dfs(x) == 1 ? "YES" : "NO") << endl;
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