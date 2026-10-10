#include <bits/stdc++.h>
using namespace std;

// 3405. Count the Number of Arrays with K Matching Adjacent Elements [H]
// LeetCode count-the-number-of-arrays-with-k-matching-adjacent-elements

int MOD = 1e9 + 7;
int modMult(int a, int b, int mod = MOD)
{
    return ((long long)(a)*b) % mod;
}

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
struct Comb
{
    vector<long long> fac, inv_fac;
    int mod;

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

    long long lucas(long long n, long long m, int p)
    {
        if (m == 0)
            return 1;
        return small_comb(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
    }

    int small_comb(int n, int k, int mod = MOD)
    {
        if (k > n || k < 0)
        {
            return 0;
        }
        return (fac[n] * inv_fac[k] % mod) * inv_fac[n - k] % mod;
    }
};

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        // m * C(n-1, k) * pow(m - 1, n - k - 1)
        Comb comb(n);
        return modMult(
            modMult(m, comb.small_comb(n - 1, k)),
            modPow(m - 1, n - k - 1)
        );
    }
};