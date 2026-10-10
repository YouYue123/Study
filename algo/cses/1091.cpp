#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector h(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> h[i];
    vector t(m, 0LL);
    for(int i = 0; i < m; i ++) cin >> t[i];
    multiset<int> h_set(h.begin(), h.end());
    // sort(h.begin(), h.end());
    
    for(int i = 0; i < m; i ++) {
        auto it = h_set.upper_bound(t[i]);
        if(it != h_set.begin()) it --;
        else {
            cout << -1 << endl;
            continue;
        }
        cout << *it << endl;
        h_set.erase(it);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}