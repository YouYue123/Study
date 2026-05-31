#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    
    auto mod_pow = [&] (ll base, ll n) -> ll{
        ll ans = 1LL;
        while(n > 0) {
            if(n % 2 == 1) {
                ans = ans * base % MOD;
                n -= 1;
            }
            base = base * base % MOD;
            n /= 2;
        }
        return ans;
    };

    cout << mod_pow(2, n) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}