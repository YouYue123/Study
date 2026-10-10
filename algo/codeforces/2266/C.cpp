#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll zero_cnt = 0;
    for(char c : s) {
        if(c == '0') zero_cnt += 1;
    }
    if(s[0] == '1') {
        cout << zero_cnt << endl;
        return;
    }
    ll ans = INF;
    ll op_cnt = 0;
    for(int i = 0; i < n; i ++) {
        char c = s[i];
        if(c == '1') {
            ans = min(
                ans, 
                // 后面的 0 全翻成 1（zero_cnt） + 前面的 1 全翻成 0（op_cnt）
                zero_cnt + op_cnt
            );
            // 对后面的分界点来说，这个 1 在左边，要翻成 0
            op_cnt += 1;
        } else {
             // 这个 0 从此落在分界点左边，保持 0 不动，不再计入“右边待翻的 0”
            zero_cnt -= 1;
        }
    }
    ans = min(ans, op_cnt);
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