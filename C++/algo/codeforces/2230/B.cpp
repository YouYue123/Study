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
    int cur = 0;
    for(char c : s) {
        if(c == '1' || c == '3') cur += 1;
    }
    int mx = cur;
    for(char c : s) {
        if(c == '2') {
            cur += 1;
        } else if(c == '1' || c == '3') {
            cur -= 1;
        }
        mx = max(mx, cur);
    }
    cout << n - mx << endl;
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