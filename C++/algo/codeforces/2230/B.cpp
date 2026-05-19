#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    string s;
    cin >> s;
    vector cnt(10, 0);
    ll ans = 0;
    // min del for only has 2 situation
    ll dp_0 = 0;
    // min del for has odd num situation
    ll dp_1 = 0;
    for(char c : s) {
        if(c == '4') {
            dp_0 += 1;
            dp_1 += 1;
        } else if(c == '2') {
            dp_1 += 1;
        } else {
            dp_1 = min(dp_0, dp_1);
            dp_0 += 1;
        }
    }
    cout << min(dp_0, dp_1) << endl;
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