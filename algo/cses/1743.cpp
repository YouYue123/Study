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
    vector cnt(26, 0LL);
    for(char c : s) cnt[c - 'A'] += 1;
    string ans = "";
    char last_c = ' ';
    for(int i = 0; i < n; i ++) {
        bool ok = false;
        int rest_len = n - i;
        for(char c = 'A'; c <= 'Z'; c ++) {
            if(c == last_c) continue;
            if(cnt[c - 'A'] > rest_len / 2) {
                ans += c;
                cnt[c - 'A'] -= 1;
                ok = true;
                break;
            }
        }
        if(!ok) {
            for(char c = 'A'; c <= 'Z'; c ++) {
                if(c == last_c) continue;
                if(cnt[c - 'A'] > 0) {
                    ans += c;
                    cnt[c - 'A'] -= 1;
                    ok = true;
                    break;
                }
            }
        }
        if(!ok) {
            cout << -1 << endl;
            return;
        }
        last_c = ans.back();
    }

    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}