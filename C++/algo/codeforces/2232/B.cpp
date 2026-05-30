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
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector presum(n + 1, 0LL);
    for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + a[i];
    vector<ll> ans;
    ll cur_max = INF;
    for(int i = 0; i < n; i ++) {
        ll avg = presum[i + 1] / (i + 1);
        cur_max = min(cur_max, avg);
        ans.push_back(cur_max);
    }
    for(int i = 0; i < n; i ++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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