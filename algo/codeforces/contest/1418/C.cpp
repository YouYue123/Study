#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];

    vector memo(n, vector(2, -1));

    auto dfs = [&] (this auto&& dfs, int i, int turn) {
        if(i == n) return 0;
        if(i == n - 1) {
            if(turn == 0) return a[i] == 1 ? 1 : 0;
            else return 0; 
        }
        if(memo[i][turn] != -1) return memo[i][turn];
        int ans = 0;
        int nxt_turn = turn ^ 1;
        if(turn == 0) {
            // friend's turn
            ans = min(
                dfs(i + 1, nxt_turn) + (a[i] == 1),
                dfs(i + 2, nxt_turn) + (a[i] == 1) + (a[i + 1] == 1)
            );
        } else {
            // my turn
            ans = min(
                dfs(i + 1, nxt_turn),
                dfs(i + 2, nxt_turn) 
            );
        }
        return memo[i][turn] = ans;
    };

    cout << dfs(0, 0) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}