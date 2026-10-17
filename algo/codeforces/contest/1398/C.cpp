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
    int cur_sum = 0;
    unordered_map<int, int> dict;
    dict[0] = 1;
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        cur_sum += s[i] - '0';
        int len = i + 1;
        int target = cur_sum - len;
        ans += dict[target];
        dict[target] += 1;
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