#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int edge_cnt = 1 << n;
    int mask = (1 << (n - 1)) - 1;
    vector visit(edge_cnt, false);
    string ans = "";
    auto dfs = [&] (auto&& dfs, int u) -> void {
        for(int c = 0; c < 2; c ++) {
            int edge_id = u * 2 + c;
            if(visit[edge_id]) continue;
            visit[edge_id] = true;
            int v = ((u << 1) | c) & mask;
            dfs(dfs, v);
            ans.push_back('0' + c);
        }
    };
    dfs(dfs, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}