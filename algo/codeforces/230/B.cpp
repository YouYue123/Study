// Problem: T-primes
// Contest: 230 | Index: B
// URL: https://codeforces.com/contest/230/problem/B
// Rating: 1300 | Tags: number theory, math, sieve
// Memory: 256 MB | Time: 2 s
// Author: Yue You

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll N = 1e6 + 1;
vector is_prime(N + 1, true);

void sieve() {
    is_prime[1] = false;
    is_prime[2] = true;
    for(int num = 2; num * num <= N; num += 1) {
        if(is_prime[num]) {
            int cur = num * num;
            while(cur <= N) {
                is_prime[cur] = false;
                cur += num;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve();
    ll n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        ll a;
        cin >> a;
        ll sqr = sqrt(a);
        if(sqr * sqr == a && is_prime[sqr] ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
