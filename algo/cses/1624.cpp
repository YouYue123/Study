#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{   
    vector<string> g(8);
    for(int i = 0; i < 8; i ++) {
        cin >> g[i];
    }
    vector<pair<int, int>> q_pos;
    auto is_valid = [&] (int row, int col) {
        for(auto& pos : q_pos) {
            if(pos.first == row) return false;
            if(pos.second == col) return false;
            if(abs(row - pos.first) == abs(col - pos.second)) return false;
        }
        return true;
    };
    auto dfs = [&] (auto& dfs, int row) -> ll {
        if(row == 8) return 1LL;
        ll ans = 0;
        for(int col = 0; col < 8; col ++) {
            if(g[row][col] == '*') continue;
            if(!is_valid(row, col)) continue;
            q_pos.emplace_back(row, col);
            ans += dfs(dfs, row + 1);
            q_pos.pop_back();
        }
        return ans;
    };
    cout << dfs(dfs, 0) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}