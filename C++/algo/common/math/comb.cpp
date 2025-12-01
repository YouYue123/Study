
#include <bits/stdc++.h>
using namespace std;

struct Comb
    vector<long long> fac, inv_fac;  // Factorial and inverse factorial arrays
    int mod;  // Modulo value
    Comb(int max_n, int mod = MOD) : mod(mod)
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
            fac[i] = (fac[i - 1] * i) % mod;
        }
        inv_fac[max_n] = modPow(fac[max_n], mod - 2, mod);
        for (int i = max_n - 1; i >= 0; --i)
        {
            inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % mod;
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
