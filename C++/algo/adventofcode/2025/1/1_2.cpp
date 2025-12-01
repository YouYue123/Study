#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int MOD = 100;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll ans = 0;     
    string line;
    long long x = 50;
    while(getline(cin, line)) {
        if (line.empty()) continue; 
        char d = line[0];
        ll steps = stoll(line.substr(1)); 
        if(d == 'L') {
            cout << "x: " << x << " steps: " << steps << endl;
            if (steps >= x) ans += (x != 0) + (steps - x) / MOD;
            x = (x - steps) % MOD;
            if (x < 0) x += MOD;
        } else {
            ll steps_to_zero = MOD - x;
            if(steps >= steps_to_zero) ans += 1 + (steps - steps_to_zero) / MOD;
            x = (x + steps) % MOD;
        }
        // cout << "x: " << x << " ans: " << ans << endl;
    }
    
    cout << ans << endl;
    return 0;
}