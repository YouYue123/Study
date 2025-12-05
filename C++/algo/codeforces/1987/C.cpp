#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i ++) cin >> h[i];
    // i == n - 1, h[i] > h[i + 1] --> h[i] = max(0, hi - 1)
    vector<ll> dp(h);
    for(int i = n - 2; i >= 0; i --) {
        dp[i] = max(dp[i], dp[i + 1] + 1);
    }
    cout << dp[0] << endl;
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