#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    // Introverts (I) who have to sit at an empty table
    // Extroverts (E) who have to sit at a non-empty table
    // Ambiverts (A) who can sit at any table.
    ll n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;
    assert((ll)u.size() == n);
    
    ll empty_table = x;
    ll available_seats = 0;
    ll upgradable_a = 0;
    ll ans = 0 ;
    for(char c : u) {
        if(c == 'I') {
            if(empty_table > 0) {
                empty_table -= 1;
                available_seats += s - 1;
                ans += 1;
            }
        } else if(c == 'E') {
            if(available_seats > 0) {
                available_seats -= 1;
                ans += 1;
            } else if(upgradable_a > 0 && empty_table > 0) {
                upgradable_a -= 1;
                empty_table -= 1;
                available_seats += s - 1;
                ans += 1;
            }
        } else if(c == 'A') {
            if(available_seats > 0) {
                available_seats -= 1;
                upgradable_a += 1;
                ans += 1;
            } else if(empty_table > 0) {
                empty_table -= 1;
                available_seats += s - 1;
                ans += 1;
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