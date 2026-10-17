#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    if(k >= 2 * n || k < n) {
        cout << -1 << endl;
        return;
    }
    int diff = k - n;
    vector ans(n, vector(n, 0LL));
    int num = n;
    for(int i = n - 1; i >= 0; i --) {
        if(diff > 0) {
            diff -= 1;
            ans[i][0] = num;
        } else {
            ans[i][i] = num;
        }
        num -= 1;
    }
    num = n + 1;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(ans[i][j] == 0) {
                cout << num << " ";
                num += 1;
            } else {
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }
    // for(int i = 0; i < n; i ++) {
    //     for(int j = 0; j < n; j ++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
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