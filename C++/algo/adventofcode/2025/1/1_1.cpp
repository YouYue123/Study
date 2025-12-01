#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int MOD = 100;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string line;
    ll x = 50;
    ll ans = 0;
    while(getline(cin, line)) {
        char d = line[0];
        ll steps = stoll(line.substr(1));
        if(d == 'L') {
            x = ((x - steps) % MOD + MOD) % MOD;
        } else {
            x = (x + steps) % MOD;
        }
        if(x == 0) ans += 1;
    }
    cout << ans << endl;
}