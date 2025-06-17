/**
 * Modulo Arithmetic Utilities
 * This file provides a collection of functions and classes for performing arithmetic operations
 * under modulo arithmetic, commonly used in competitive programming and cryptography.
 */

#include <vector>
using namespace std;
constexpr int MOD = 1e9 + 7;  // Default modulo value (10^9 + 7)

/**
 * Adds two numbers under modulo arithmetic
 * @param a First number
 * @param b Second number
 * @param mod Modulo value (default: MOD)
 * @return (a + b) % mod
 */
int modPlus(int a, int b, int mod = MOD)
{
    return ((long long)(a) + b) % mod;
}

/**
 * Subtracts two numbers under modulo arithmetic
 * @param a First number
 * @param b Second number
 * @param mod Modulo value (default: MOD)
 * @return (a - b) % mod (handles negative results correctly)
 */
int modMinus(int a, int b, int mod = MOD)
{
    return (((long long)(a)-b) + mod) % mod;
}

/**
 * Multiplies two numbers under modulo arithmetic
 * @param a First number
 * @param b Second number
 * @param mod Modulo value (default: MOD)
 * @return (a * b) % mod
 */
int modMult(int a, int b, int mod = MOD)
{
    return ((long long)(a)*b) % mod;
}

/**
 * Computes base raised to power under modulo arithmetic using binary exponentiation
 * @param base Base number
 * @param exp Exponent
 * @param mod Modulo value (default: MOD)
 * @return (base^exp) % mod
 */
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

/**
 * Computes modular multiplicative inverse using Fermat's little theorem
 * Note: Only works when mod is prime
 * @param a Number to find inverse of
 * @param mod Modulo value (default: MOD)
 * @return a^(-1) % mod
 */
int modInv(int a, int mod = MOD)
{
    // prime mod only, using Fermat's little theorem.
    return modPow(a, mod - 2);
}

/**
 * Divides two numbers under modulo arithmetic
 * @param a Numerator
 * @param b Denominator
 * @param mod Modulo value (default: MOD)
 * @return (a / b) % mod
 */
int modDiv(int a, int b, int mod = MOD) { return modMult(a, modInv(b)); }

/**
 * Combination class for computing combinations and permutations under modulo arithmetic
 * Supports both small combinations and Lucas theorem for large numbers
 */
struct Comb
{
    vector<long long> fac, inv_fac;  // Factorial and inverse factorial arrays
    int mod;  // Modulo value

    /**
     * Constructor that precomputes factorials and their inverses
     * @param max_n Maximum value of n for which combinations will be computed
     * @param mod Modulo value (default: MOD)
     */
    Comb(int max_n, int mod = MOD) : mod(mod)
    {
        precompute(max_n);
    }

    /**
     * Precomputes factorials and their modular inverses up to max_n
     * @param max_n Maximum value to precompute
     */
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

    /**
     * Computes combination C(n,m) using Lucas theorem for large numbers
     * @param n Total number of items
     * @param m Number of items to choose
     * @param p Prime modulo value
     * @return C(n,m) % p
     */
    long long lucas(long long n, long long m, int p)
    {
        if (m == 0)
            return 1;
        return small_comb(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
    }

    /**
     * Computes combination C(n,k) for small numbers using precomputed factorials
     * @param n Total number of items
     * @param k Number of items to choose
     * @param mod Modulo value (default: MOD)
     * @return C(n,k) % mod
     */
    int small_comb(int n, int k, int mod = MOD)
    {
        if (k > n || k < 0)
        {
            return 0;
        }
        return (fac[n] * inv_fac[k] % mod) * inv_fac[n - k] % mod;
    }
};
