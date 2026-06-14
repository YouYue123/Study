#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    

    vector memo(n, vector(m, -1));
    auto dfs = [&] (auto& dfs, int i, int j) {
        if(i == n) return m - j;
        if(j == m) return n - i;
        if(memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        if(a[i] == b[j]) {
            ans = dfs(dfs, i + 1, j + 1);
        } else {
            ans = 1 + min({
                dfs(dfs, i + 1, j),
                dfs(dfs, i, j + 1),
                dfs(dfs, i + 1, j + 1)
            });
        }
        return memo[i][j] = ans;
    };

    cout << dfs(dfs, 0, 0) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}