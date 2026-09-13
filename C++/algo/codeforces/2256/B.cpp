#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto validate = [&] (string s) {
        for(int i = 0; i < n - 2; i ++) {
            if(s[i + 2] == '?') s[i + 2] = s[i] == '0' ? '1' : '0';
            else if(s[i] == s[i + 2]) return false;
        }
        return true;
    };
    int ans = 0;
    if(s[0] == '?') {
        if(s[1] == '?') {
            s[0] = '0';
            s[1] = '0';
            if(validate(s)) ans += 1;
            s[0] = '0';
            s[1] = '1';
            if(validate(s)) ans += 1;
            s[0] = '1';
            s[1] = '0';
            if(validate(s)) ans += 1;
            s[0] = '1';
            s[1] = '1';
            if(validate(s)) ans += 1;
        } else {
            s[0] = '0';
            if(validate(s)) ans += 1;
            s[0] = '1';
            if(validate(s)) ans += 1;
        }
    } else if(s[1] == '?') {
        s[1] = '0';
        if(validate(s)) ans += 1;
        s[1] = '1';
        if(validate(s)) ans += 1;
    } else {
        if(validate(s)) ans = 1;
        else ans = 0;
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