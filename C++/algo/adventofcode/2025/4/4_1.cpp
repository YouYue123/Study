#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string line;
    ull ans = 0;
    vector<string> grid;
    while(getline(cin, line)) grid.push_back(line);
    vector<pair<int, int>> dirs = {
        {-1,  0}, {1,  0},
        {0,   1}, {0, -1},
        {-1, -1}, {1,  1},
        { 1, -1}, {-1, 1}
    };
    int n = grid.size(), m = grid[0].size();
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(grid[i][j] != '@') continue;
            int cnt = 0;
            for(auto& d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                if(ni < n && ni >= 0 && nj < m && nj >= 0) {
                    cnt += grid[ni][nj] == '@';
                }
            }
            if(cnt < 4) ans += 1;
        }
    }
    cout << "ans:" << ans << endl;
}