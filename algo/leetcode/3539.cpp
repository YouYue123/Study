#include <bits/stdc++.h>
using namespace std;

// 3539. Find Sum of Array Product of Magical Sequences [H]
// LeetCode find-sum-of-array-product-of-magical-sequences

class Solution {
private:
    const long long MOD = 1000000007;
    vector<long long> fact, inv_fact;

    // Modular exponentiation: computes (base^exp) % MOD
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    // Initialize factorials and their inverses up to max_n
    void initFactorials(int max_n) {
        fact.resize(max_n + 1);
        inv_fact.resize(max_n + 1);
        fact[0] = 1;
        for (int i = 1; i <= max_n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        // Compute inverse of fact[max_n] and derive others
        inv_fact[max_n] = modPow(fact[max_n], MOD - 2);
        for (int i = max_n - 1; i >= 0; --i) {
            inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
        }
    }

public:
    int magicalSum(int M, int K, vector<int>& nums) {
        initFactorials(M); // Initialize factorials up to M

        // Memoization map: key = (mask, m, k, depth), value = sum of products
        map<tuple<int, int, int, int>, long long> memo;

        // Recursive function f(mask, m, k, depth)
        function<long long(int, int, int, int)> f = [&](int mask, int m, int k, int depth) -> long long {
            // Check memoization
            auto key = make_tuple(mask, m, k, depth);
            if (memo.count(key)) {
                return memo[key];
            }

            // Base cases
            if (m == 0) {
                return (__builtin_popcount(mask) == k) ? 1 : 0;
            }
            if (depth == (int)nums.size()) {
                return 0;
            }

            long long res = 0;

            // Pick 0 (exclude current number)
            res = (res + f(mask >> 1, m, k - (mask & 1), depth + 1)) % MOD;

            // Pick c > 0
            for (int c = 1; c <= m; ++c) {
                int nmask = mask + c;
                int nm = m - c;
                int nk = k - (nmask & 1);
                long long sp = f(nmask >> 1, nm, nk, depth + 1);
                // Compute: (fact(m) * inv(fact(m-c)) * nums[depth]^c * sp * inv(fact(c))) % MOD
                long long term = fact[m];
                term = (term * inv_fact[m - c]) % MOD;
                term = (term * modPow(nums[depth], c)) % MOD;
                term = (term * sp) % MOD;
                term = (term * inv_fact[c]) % MOD;
                res = (res + term) % MOD;
            }

            return memo[key] = res;
        };

        return f(0, M, K, 0);
    }
};