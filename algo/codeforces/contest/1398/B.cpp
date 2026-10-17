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
    int n = s.size();
    vector<int> cnts;
    int i = 0;
    while(i < n) {
        if(s[i] == '1') {
            int cnt = 0;
            while(i < n && s[i] == '1') {
                i += 1;
                cnt += 1;
            }
            cnts.push_back(cnt);
        } else {
            i += 1;
        }
        // cout << i << endl;
    }
    sort(cnts.begin(), cnts.end(), greater<>());
    ll ans = 0;
    for(int i = 0; i < cnts.size(); i += 2) {
        ans += cnts[i];
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