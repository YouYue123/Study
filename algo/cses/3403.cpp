#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, 0LL), b(m, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];
    vector memo(n, vector(m, -1));
    auto dfs = [&] (auto& dfs, int i, int j) {
        if(i == n || j == m) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 1 + dfs(dfs, i + 1, j + 1);
        } else {
            ans = max(
                dfs(dfs, i + 1, j), 
                dfs(dfs, i, j + 1)
            );
        }
        return memo[i][j] = ans;
    };
    cout << dfs(dfs, 0, 0) << endl;

    int i = 0, j = 0;
    vector<ll> ans;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            ans.push_back(a[i]);
            i += 1;
            j += 1;
        } else {
            int val_down = i + 1 < n ? memo[i + 1][j] : 0;
            int val_right = j + 1 < m ? memo[i][j + 1] : 0;
            if(val_down >= val_right) {
                i += 1;;
            } else {
                j += 1;
            }
        }
    }

    for(auto& item : ans) cout << item << " ";
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}