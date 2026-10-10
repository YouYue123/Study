
#include <bits/stdc++.h>
#include "mod.cpp"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr MOD = 1e9 + 7;
struct Comb {
    vector<long long> fac, inv_fac; 
    Comb(int max_n, int mod = MOD)
    {
        precompute(max_n);
    }
    void precompute(int max_n)
    {
        fac.resize(max_n + 1);
        inv_fac.resize(max_n + 1);
        fac[0] = 1;
        for (int i = 1; i <= max_n; ++i)
        {
            fac[i] = (fac[i - 1] * i) % MOD;
        }
        inv_fac[max_n] = modPow(fac[max_n], MOD - 2, MOD);
        for (int i = max_n - 1; i >= 0; --i)
        {
            inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % MOD;
        }
    }

    // https://oi-wiki.org/math/number-theory/lucas/
    long long lucas(long long n, long long m, int p)
    {
        if (m == 0)
            return 1;
        return small_comb(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
    }

    // https://oi-wiki.org/math/combinatorics/combination/
    int small_comb(int n, int k, int mod = MOD)
    {
        if (k > n || k < 0)
        {
            return 0;
        }
        return (fac[n] * inv_fac[k] % mod) * inv_fac[n - k] % mod;
    }
};
