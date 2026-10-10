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
    
    int cnt = 0;
    char prev = ' ';
    int ans = 0;
    for(char c : s) {
        if(prev == c) {
            cnt += 1;
        } else {
            cnt = 1;
        }
        ans = max(ans, cnt);
        prev = c;
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}