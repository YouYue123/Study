#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
 
void solve()
{
    string s;
    cin >> s;
    ll n_b, n_s, n_c;
    cin >> n_b >> n_s >> n_c;
    ll p_b, p_s, p_c;
    cin >> p_b >> p_s >> p_c;
    ll r;
    cin >> r;
    ll cnt_b = 0, cnt_s = 0, cnt_c = 0;
    for(char c : s) {
        if(c == 'B') cnt_b += 1;
        else if(c == 'S') cnt_s += 1;
        else if(c == 'C') cnt_c += 1;
    }
    auto is_valid = [&] (ll x) -> bool {
        __int128 cost_b = max((x * cnt_b - n_b) * p_b, 0LL);
        __int128 cost_s = max((x * cnt_s - n_s) * p_s, 0LL);
        __int128 cost_c = max((x * cnt_c - n_c) * p_c, 0LL);
        // cout << "for x: " << x << endl;
        // cout << "cost_b: " << cost_b << " cost_s: " << cost_s << " cost_c: " << cost_c << endl;
        return (cost_b + cost_s + cost_c) <= (__int128)r;
    };
 
    ll left = -1, right = r + max({n_b, n_s, n_s}) + 1;
    while(left + 1 < right) {
        ll mid = left + (right - left) / 2;
        if(is_valid(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
 
    cout << left << endl;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}