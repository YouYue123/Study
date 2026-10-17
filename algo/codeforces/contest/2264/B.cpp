#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    priority_queue<int> pq;
    ll cur_sum = 0;
    // i * b(m) - (b(m-1) + b(m-2) + ... + b(1)) 
    ll ans = -INF;
    for(int i = 0; i < n; i ++) {
        // cout << "cur_sum: " << cur_sum << endl;
        if(pq.size() == m - 1) ans = max(ans, m * a[i] - cur_sum);
        cur_sum += a[i];
        pq.push(a[i]);
        if(pq.size() > m - 1) {
            cur_sum -= pq.top();
            pq.pop();
        }
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