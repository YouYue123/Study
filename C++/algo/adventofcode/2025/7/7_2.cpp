#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ull, ull>;
int main() {
    auto start = chrono::high_resolution_clock::now();
    ll ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ll>> nums;
    string line = "";
    vector<string> g;
    while(getline(cin, line)) g.push_back(line);
    int n = g.size(), m = g[0].size();
    int sCol = 0;
    for(int j = 0; j < m; j ++) {
        if(g[0][j] == 'S') sCol = j;
    }
    vector memo(n, vector(m, -1LL));
    auto dfs = [&] (this auto&& dfs, int row, int col) -> ll {
        if(row == n - 1) return 1;
        if(col < 0 || col >= m) return 0;
        if(memo[row][col] != -1) return memo[row][col];
        int nRow = row + 1;
        long long ans = 0LL;
        if(g[nRow][col] == '^') {
            ans = ans + dfs(nRow, col - 1) + dfs(nRow, col + 1);
        } else {
            ans = dfs(nRow, col);
        }
        return memo[row][col] = ans;
    };
    ans = dfs(0, sCol);
    cout << "ans:" << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}