#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;
    
    ll empty_tables = x;
    ll partial_seats = 0;
    ll upgradable_A = 0;
    ll ans = 0;
    
    for (char c : u) {
        if (c == 'I') {
            if (empty_tables > 0) {
                empty_tables--;
                partial_seats += (s - 1);
                ans++;
            }
        } else if (c == 'E') {
            if (partial_seats > 0) {
                partial_seats--;
                ans++;
            } else if (upgradable_A > 0 && empty_tables > 0) {
                upgradable_A--;
                empty_tables--;
                partial_seats += (s - 1);
                ans++;
            }
        } else if (c == 'A') {
            if (partial_seats > 0) {
                partial_seats--;
                upgradable_A++;
                ans++;
            } else if (empty_tables > 0) {
                empty_tables--;
                partial_seats += (s - 1);
                ans++;
            }
        }
    }
    
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}