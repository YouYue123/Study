#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll const MAX_N = 1e6;
vector<bool> is_prime(MAX_N + 1, true);
vector<ll> primes;
void sieve() {
    
    for(ll num = 2; num <= MAX_N; num ++) {
        if(is_prime[num]) {
            ll cur = num * num;
            while(cur > 0 && cur <= MAX_N) {
                is_prime[cur] = false;
                cur += num;
            }
            primes.push_back(num);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    // cout << primes.size() << endl;
    for(int i = 0; i < n; i ++) {
        cout << primes[i] * primes[i + 1] << " ";
    }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve();
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}