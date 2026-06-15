#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
void solve() {
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    
    vector<ll> g;

    for(int i = 0; i < n; i ++) {
        // cout << i << endl;
        auto it = lower_bound(g.begin(), g.end(), a[i]);
        if(it == g.end()) {
            // cout << "find!" << endl;
            g.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << g.size() << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}