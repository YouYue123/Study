#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    int i;
    int j;
    int dist;
    bool operator< (const Item& other) const {
        return dist < other.dist;
    }
    bool operator> (const Item& other) const {
        return dist > other.dist;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> dirs = {
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
        {2, 1}, {-2, 1}, {2, -1}, {-2, -1}
    };

    vector dist(n, vector(n, INF));
    dist[0][0] = 0LL;
    queue<Item> q;
    q.emplace(0, 0, 0);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto& dir : dirs) {
            int n_i = cur.i + dir.first, n_j = cur.j + dir.second, n_dist = cur.dist + 1;
            if(n_i < 0 || n_i >= n || n_j < 0 || n_j >= n)  continue;
            if(dist[n_i][n_j] != INF) continue;
            dist[n_i][n_j] = n_dist;
            q.emplace(n_i, n_j, n_dist);
        }
    }
    // vector visit(n, vector(n, false));
    // auto dfs = [&] (this auto&& dfs, int i, int j) -> ll {
    //     // cout << i << " " << j << endl;
    //     if(memo[i][j] != -1) return memo[i][j];
    //     ll ans = INF;
    //     for(auto& dir : dirs) {
    //         int n_i = i + dir.first, n_j = j + dir.second;
    //         if(n_i < 0 || n_i >= n || n_j < 0 || n_j >= n)  continue;
    //         if(visit[n_i][n_j]) continue;;
    //         visit[n_i][n_j] = true;
    //         ans = min(ans, 1 + dfs(n_i, n_j));
    //         visit[n_i][n_j] = false;
    //     }  
    //     return memo[i][j] = ans;
    // };
    // dfs(n - 1, n - 1);

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}