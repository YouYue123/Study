
#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
using ll = long long;
// https://oi-wiki.org/math/number-theory/mod-arithmetic/

ll modPlus(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }

ll modMinus(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }

ll modMult(ll a, ll b, ll mod = MOD) { return a * b % mod; }

ll modPow(ll base, ll exp, ll mod = MOD)
{
    ll result = 1;
    while (exp)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }

    return result;
}

// prime mod only, Fermat's little theorem.
ll modInv(ll a, ll mod = MOD) { return modPow(a, mod - 2); }

ll modDiv(ll a, ll b, ll mod = MOD) { return modMult(a, modInv(b)); }
