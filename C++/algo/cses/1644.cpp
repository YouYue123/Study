#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    vector presum(n + 1, 0LL);
    for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + x[i];
    int right = a;
    deque<ll> q;
    ll ans = -INF;
    while(right <= n) {
        int left = right - a;
        while(!q.empty() && presum[q.back()] >= presum[left]) {
            q.pop_back();
        }
        q.push_back(left);
        ans = max(ans, presum[right] - presum[q.front()]);
        if(right - q.front() == b) q.pop_front();
        right += 1;
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}