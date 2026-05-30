#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;
    ll empty_table_cnt = x;
    ll avaialble_seat_cnt = 0; 
    ll ans = 0;
    for(char c : u) {
        if(c == 'I') {
            if(empty_table_cnt > 0) {
                empty_table_cnt -= 1;
                ans += 1;
                if(s > 1) {
                    avaialble_seat_cnt += (s - 1);
                }
            } 
        } else if(c == 'E') {
            if(avaialble_seat_cnt > 0) {
                avaialble_seat_cnt -= 1;
                ans += 1;
            }
        } else if(c == 'A') {
            if(avaialble_seat_cnt > 0) {
                avaialble_seat_cnt -= 1;
                ans += 1;
            } else if(empty_table_cnt > 0) {
                empty_table_cnt -= 1;
                ans += 1;
                if(s > 1) avaialble_seat_cnt += (s - 1);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}