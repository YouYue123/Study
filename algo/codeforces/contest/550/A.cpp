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
    int occ_ab = -1, occ_ba = -1;
    string ans = "NO";
    for(int i = 0; i < n - 1; i ++) {
        if(s[i] == 'A' && s[i + 1] == 'B') {
            if(occ_ab == -1) occ_ab = i;
            if(occ_ba != -1 && occ_ba != i - 1) {
                ans = "YES";
                break;
            }
        }
        if(s[i] == 'B' && s[i + 1] == 'A') {
            if(occ_ba == -1) occ_ba = i;
            if(occ_ab != -1 && occ_ab != i - 1) {
                ans = "YES";
                break;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}