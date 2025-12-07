#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ull, ull>;
int main() {
    auto start = chrono::high_resolution_clock::now();
    ull ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ull>> nums;
    string line = "";
    vector<string> g;
    while(getline(cin, line)) g.push_back(line);
    int n = g.size(), m = g[0].size();
    int sCol = 0;
    for(int j = 0; j < m; j ++) {
        if(g[0][j] == 'S') sCol = j;
    }
    vector memo(n, vector(m, ULLONG_MAX));
    auto dfs = [&] (this auto&& dfs, int row, int col) -> ull {
        if(row == n - 1) return 1ULL;
        if(col < 0 || col >= m) return 0ULL;
        if(memo[row][col] != ULLONG_MAX) return memo[row][col];
        int nRow = row + 1;
        long long ans = 0ULL;
        if(g[nRow][col] == '^') {
            ans += dfs(nRow, col - 1);
            ans += dfs(nRow, col + 1);
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