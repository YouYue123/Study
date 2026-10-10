#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector g(n + 1, vector<ll>());
    vector in_order(n + 1, 0LL);
    for(int i = 0; i < m; i ++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        in_order[b] += 1;
    }
    queue<int> q;
    for(int i = 1; i <= n; i ++) {
        if(in_order[i] == 0) q.push(i);
    }
    vector<ll> ans;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto nxt : g[cur]) {
            in_order[nxt] -= 1;
            if(in_order[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    if(ans.size() == n) {
        for(auto item : ans) cout << item << " ";
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}