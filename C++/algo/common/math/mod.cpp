
#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;

// https://oi-wiki.org/math/number-theory/mod-arithmetic/

int modPlus(int a, int b, int mod = MOD) { return ((long long)(a) + b) % mod; }

int modMinus(int a, int b, int mod = MOD) { return (((long long)(a)-b) + mod) % mod; }

int modMult(int a, int b, int mod = MOD) { return ((long long)(a)*b) % mod; }

int modPow(int base, int exp, int mod = MOD)
{
    long long result = 1;
    while (exp)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = ((long long)base * base) % mod;
    }

    return result;
}

// prime mod only, Fermat's little theorem.
int modInv(int a, int mod = MOD) { return modPow(a, mod - 2); }

int modDiv(int a, int b, int mod = MOD) { return modMult(a, modInv(b)); }
