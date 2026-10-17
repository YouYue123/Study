#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    int l = 0, r = s.size() - 1;
    int ans = 0;
    while(l < r) {
        if(s[l] != s[r]) {
            if(s[l] == c || s[r] == c) {
                ans += 1;
            } else {
                ans += 2;
            }
        } 
        l += 1;
        r -= 1;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}