#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    int n;
    cin >> n;
    map<ll, set<ll>> dict;
    ll mx_a = 0;
    for(int i = 0; i < n; i ++) {
        ll a, b;
        cin >> a >> b;
        dict[a].insert(b);
    }
    ll ans = 0;
    for(auto& [a, b_set] : dict) {
        int min_b = *b_set.begin();
        if(ans > min_b) ans = a;
        else ans = *(prev(b_set.end()));
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}