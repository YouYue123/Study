#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector w(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> w[i];
    if(n % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    int i = 0;
    ll cur_min = -INF, cur_max = INF;
    while(i < n) {
        if(w[i + 1] >= cur_max - 1 || w[i] <= cur_min + 1) {
            cout << "NO" << endl;
            return;
        }
        cur_max = min(cur_max, w[i]);
        cur_min = max(cur_min, w[i + 1]);
        if(cur_max - cur_min <= 1) {
            cout << "NO" << endl;
            return;
        }
        i += 2;
    }
    cout << "YES" << endl;
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