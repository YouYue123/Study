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
    string s;
    cin >> s;
    int cnt = 0;
    for(char c : s) {
        if(c == '*') cnt += 1;
    }
    int cur = 0, median_idx = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '*') cur += 1;
        if(cur == (cnt / 2 + 1) ) {
            median_idx = i;
            break;
        }
    }
    // cout << "median_idx: " << median_idx << endl;
    cur = median_idx - cnt / 2;
    // cout << cur << endl;
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '*') {
            ans += abs(cur - i);
            cur += 1;
        }
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