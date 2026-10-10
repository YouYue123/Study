#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Edge { ll a, b, c; };
void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0; i < m; i ++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    vector dist(n + 1, 0LL);
    vector parent(n + 1, 0LL);
    for(int i = 1; i <= n; i ++) {
        for(auto& [a, b, c] : edges) {
            if(dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                parent[b] = a;
                if(i == n) {
                    ll start = a;
                    for (int j = 0; j < n; j++) start = parent[start];
                    cout << "YES" << endl;
                    vector<ll> ans;
                    ll cur = start;
                    do {
                        ans.push_back(cur);
                        cur = parent[cur];
                    } while (cur != start);
                    ans.push_back(start); 
                    reverse(ans.begin(), ans.end());
                    for (auto item : ans) cout << item << " ";
                    cout << endl;
                    return;
                } 
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}