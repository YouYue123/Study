#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector b(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> b[i];
    
    // pa[i] stands for the earlist day for episode i in the future
    // pa[i] == n means it never happens
    vector<int> pa(n + 2, n), pb (n + 2, n);
    // dp[i] stands for if at day i both watched the same episode, the furthest day it can reach
    vector<int> dp(n, n - 1);

    ll ans = 0;
    for(int L = n - 1; L >= 0; L--) {
        int episode_a = a[L], episode_b = b[L];
        pa[episode_a] = L;
        pb[episode_b] = L;

        if(episode_a == episode_b) {
            int nxt_episode = episode_a + 1;
            if(nxt_episode <= n + 1) {
                if(pa[nxt_episode] == pb[nxt_episode]) {
                    dp[L] = (pa[nxt_episode] == n) ? n - 1 : dp[pa[nxt_episode]];
                } else {
                    dp[L] = min(pa[nxt_episode], pb[nxt_episode]) - 1;
                }
            }
        }
        int R = 0;
        if(pa[1] == pb[1]) {
            R = (pa[1] == n) ? n - 1 : dp[pa[1]];
        } else {
            R = min(pa[1], pb[1]) - 1;
        }
        ans += (R - L + 1);
    }
    cout << ans << endl;
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