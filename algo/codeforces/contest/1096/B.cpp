#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n % 2 == 1) cout << "NO" << endl;
    else {
        int cnt = 0;
        for(char c : s) {
            if(c == '(') {
                cnt += 1;
            } else {
                cnt -= 1;
            }
        }
        if(cnt == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
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