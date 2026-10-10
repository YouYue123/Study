#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<ll> b(m);
    for(int i = 0; i < m; i ++) cin >> b[i];
    int p1 = 0, p2 = 0;
    vector<pair<ll, ll>> ans;
    while(p1 < n && p2 < m) {
        if(a[p1] - x <= b[p2] && a[p1] + y >= b[p2]) {
            ans.emplace_back(p1 + 1, p2 + 1);
            p1 += 1;
            p2 += 1;
        } else if(a[p1] - x > b[p2]) {
            p2 += 1;
        } else { // a[p1] + y < b[p2]
            p1 += 1;
        }
    }
    cout << ans.size() << endl;
    for(auto& item : ans) {
        cout << item.first << " " << item.second << endl;
    }
}