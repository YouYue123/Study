#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Move {
    int degree;
    int n_i;
    int n_j;
};
void solve() {
    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    vector g(8, vector(8, -1));
    vector<pair<int, int>> dirs = {
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
        {2, 1}, {-2, 1}, {2, -1}, {-2, -1}
    };

    auto degree = [&] (int i, int j) {
        int cnt = 0;
        for(auto& dir: dirs) {
            int n_i = i + dir.first, n_j = j + dir.second;
            if(n_i < 0 || n_i >= 8 || n_j < 0 || n_j >= 8) continue;
            if(g[n_i][n_j] != -1) continue;
            cnt += 1;
        }
        return cnt;
    };

    auto dfs = [&] (auto& dfs, int i, int j, int cnt) {
        if(cnt == 65) return true;
        vector<Move> moves;
        for(auto& dir: dirs) {
            int n_i = i + dir.first, n_j = j + dir.second;
            if(n_i < 0 || n_i >= 8 || n_j < 0 || n_j >= 8) continue;
            if(g[n_i][n_j] != -1) continue;
            moves.emplace_back(degree(n_i, n_j), n_i, n_j);
        }
        sort(moves.begin(), moves.end(), [&] (auto& a, auto& b) {
            return a.degree < b.degree;
        });
        for(auto& [ _, n_i, n_j ] : moves) {
            g[n_i][n_j] = cnt;
            if(dfs(dfs, n_i, n_j, cnt + 1)) return true;
            g[n_i][n_j] = -1;
        }
        return false;
    };

    g[y][x] = 1;
    dfs(dfs, y, x, 2);

    for(auto& row : g) {
        for(int item: row) {
            cout << item << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}