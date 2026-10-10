#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    string s;
    cin >> s;
    bool visit[9][9];
    memset(visit, false, sizeof(visit));
    for(int i = 0 ; i < 9; i ++) {
        visit[0][i] = true;
        visit[8][i] = true;
        visit[i][0] = true;
        visit[i][8] = true;
    }
    vector<pair<int, int>> dirs = {
        make_pair(1, 0),  
        make_pair(-1, 0),  
        make_pair(0, -1),  
        make_pair(0, 1) 
    };

    auto is_valid = [&] (int i, int j) {
        // return true;
        if(visit[i - 1][j] && visit[i + 1][j]) {
            if(!visit[i][j - 1] && !visit[i][j + 1]) return false;
        } 
        if(visit[i][j - 1] && visit[i][j + 1]) {
            if(!visit[i + 1][j] && !visit[i - 1][j]) return false;
        }
        return true;
    };
    auto dfs = [&] (auto& dfs, int i, int j, int cnt) {
        // cout << "i: " << i << " j: " << j << " cnt: " << cnt << endl;
        if(i == 7 && j == 1) {
            return cnt == s.size() ? 1 : 0;
        }
        if(cnt == s.size() || !is_valid(i, j)) return 0;
        if(abs(7 - i) + abs(1 - j) > s.size() - cnt) return 0;
        int ans = 0;
        char c = s[cnt];
        if(c == '?') {
            for(auto& dir: dirs) {
                int n_i = i + dir.first, n_j = j + dir.second, n_cnt = cnt + 1;
                if(!visit[n_i][n_j]) {
                    visit[n_i][n_j] = true;
                    ans += dfs(dfs, n_i, n_j, n_cnt);
                    visit[n_i][n_j] = false;
                }
            }
        } else {
            int idx = 0;
            if(c == 'D') idx = 0;
            else if(c == 'U') idx = 1;
            else if(c == 'L') idx = 2;
            else if(c == 'R') idx = 3;
            auto dir = dirs[idx];
            int n_i = i + dir.first, n_j = j + dir.second, n_cnt = cnt + 1;
            if(!visit[n_i][n_j]) {
                visit[n_i][n_j] = true;
                ans = dfs(dfs, n_i, n_j, n_cnt);
                visit[n_i][n_j] = false;
            }
           
        }
        return ans;
    };
    visit[1][1] = true;
    cout << dfs(dfs, 1, 1, 0) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}