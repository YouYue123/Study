#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    int x;
    int y;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) cin >> g[i];
    vector<pair<int, int>> dirs = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    vector<char> dir_chars = { 'D', 'R', 'U','L' };
    vector parent(n, vector(m, make_pair(-1, -1)));
    vector directions(n, vector(m, ' '));
    vector visit(n, vector(m, false));
    string ans = "";

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == 'A') {
                queue<Item> q;
                q.emplace(i, j);
                visit[i][j] = true;
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if(g[cur.x][cur.y] == 'B') {
                        cout << "YES" << endl;
                        auto cur_pos = make_pair(cur.x, cur.y);
                        string ans = "";
                        while(cur_pos.first != i || cur_pos.second != j) {
                            ans += directions[cur_pos.first][cur_pos.second];
                            cur_pos = parent[cur_pos.first][cur_pos.second];
                        }
                        cout << ans.size() << endl;
                        reverse(ans.begin(), ans.end());
                        cout << ans << endl;
                        return;
                    }
                    for(int k = 0; k < 4; k ++) {
                        auto& dir = dirs[k];
                        int n_x = cur.x + dir.first, n_y = cur.y + dir.second;
                        if(n_x >= n || n_x < 0 || n_y >= m || n_y < 0) continue;
                        if(visit[n_x][n_y] || g[n_x][n_y] == '#') continue;
                        visit[n_x][n_y] = true;
                        directions[n_x][n_y] = dir_chars[k];
                        parent[n_x][n_y] = { cur.x, cur.y };
                        q.emplace(n_x, n_y );
                    }
                }
                cout << "NO" << endl;
                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}