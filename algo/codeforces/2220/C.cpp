#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int constexpr INF = 0x3f3f3f3f;

void solve()
{
    ll p, q;
    cin >> p >> q;
    ll n = 1;
    ll S = p + 2 * q;
    int limit = sqrt(S / 2);
    while(n <= limit ) {
        ll top = S - n;
        ll down = 2 * n + 1;
        if(top > 0 && top % down == 0) {
            ll m = top / down;
            long long diff = abs(m - n);
            if(p >= diff) {
                cout << n << " " << m << endl;
                return;
            }
        }
        n += 1;
    }
    cout << -1 << endl;
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