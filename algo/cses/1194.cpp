#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    int x;
    int y;
    int dist;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) cin >> g[i];
    vector<pair<int, int>> dirs = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    vector<char> dir_chars = {
        'D', 'U', 'R', 'L'
    };
    pair<int, int> a_pos = {-1, -1};
    vector a_dist(n, vector(m, INF));
    vector parent(n, vector<pair<int, int>>(m));
    vector from_dir(n, vector(m, ' '));
    vector m_dist(n, vector(m, INF));
    queue<Item> m_q;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == 'A') {
                a_pos = make_pair(i, j);
                queue<Item> q;
                q.emplace(i, j, 0);
                a_dist[i][j] = 0;
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k ++) {
                        auto& dir = dirs[k];
                        int n_x = cur.x + dir.first, n_y = cur.y + dir.second;
                        int n_dist = cur.dist + 1;
                        if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) continue;
                        if(g[n_x][n_y] != '.' || a_dist[n_x][n_y] != INF) continue;
                        from_dir[n_x][n_y] = dir_chars[k];
                        parent[n_x][n_y] = { cur.x, cur.y };
                        a_dist[n_x][n_y] = n_dist;
                        q.emplace(n_x, n_y, n_dist);
                    }
                }
            }
            if(g[i][j] == 'M') {
                m_q.emplace(i, j, 0);
                m_dist[i][j] = 0;
            }
        }
    }

    while(!m_q.empty()) {
        auto cur = m_q.front();
        m_q.pop();
        for(auto& dir : dirs) {
            int n_x = cur.x + dir.first, n_y = cur.y + dir.second;
            int n_dist = cur.dist + 1;
            if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) continue;
            if((g[n_x][n_y] != '.' && g[n_x][n_y] != 'A') || m_dist[n_x][n_y] <= n_dist) continue;
            m_dist[n_x][n_y] = n_dist;
            m_q.emplace(n_x, n_y, n_dist);
        }
    }

    // cout << "a_dist" << endl;
    // for(int i = 0; i < n; i ++) {
    //     for(int j = 0; j < m; j ++) {
    //         cout << a_dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "m_dist" << endl;
    // for(int i = 0; i < n; i ++) {
    //     for(int j = 0; j < m; j ++) {
    //         cout << m_dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    string ans = "";
    bool has_ans = false;
    auto get_ans = [&] (int i, int j) {
        if(a_dist[i][j] < m_dist[i][j]) {
            auto cur = make_pair(i, j);
            while(cur != a_pos) {
                ans += from_dir[cur.first][cur.second];
                cur = parent[cur.first][cur.second];
            }
            has_ans = true;
        }
    };
    for(int i = 0; i < n; i ++) {
        if(!has_ans && (g[i][0] == '.' || g[i][0] == 'A')) {
            // cout << "boundary found! " << i << " " << 0 << endl;
            // cout << "a_dist: " << a_dist[i][0] << " m_dist: " << m_dist[i][0] << endl;
            get_ans(i, 0);
        } else if(!has_ans && (g[i][m - 1] == '.' || g[i][m - 1] == 'A')) {
            // cout << "boundary found! " << i << " " << m - 1 << endl;
            // cout << "a_dist: " << a_dist[i][m - 1] << " m_dist: " << m_dist[i][m - 1] << endl;
            get_ans(i, m - 1);
        }
    }
    for(int j = 0; j < m; j ++) {
        if(!has_ans && (g[0][j] == '.' || g[0][j] == 'A')) {
            // cout << "boundary found! " << 0 << " " << j << endl;
            // cout << "a_dist: " << a_dist[0][j] << " m_dist: " << m_dist[0][j] << endl;
            get_ans(0, j);
        } else if(!has_ans && (g[n - 1][j] == '.' || g[n - 1][j] == 'A')) {
            // cout << "boundary found! " << n - 1 << " " << j << endl;
            // cout << "a_dist: " << a_dist[n - 1][j] << " m_dist: " << m_dist[n - 1][j] << endl;
            get_ans(n - 1, j);
        }
    }
    if(!has_ans) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}