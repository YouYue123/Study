#include <bits/stdc++.h>
using namespace std;

// 2338. Count the Number of Ideal Arrays [H]
// LeetCode count-the-number-of-ideal-arrays


class Solution {
public:
    const int MAXV = 10000;
    const int MAXB = 13;
    const int MOD = 1000000007;
    vector<long long> fact;
    vector<long long> invfact;
    vector<vector<int>> cnt;

    Solution() {
        fact.resize(MAXV + 1);
        invfact.resize(MAXV + 1);
        cnt.assign(MAXV + 1, vector<int>(MAXB + 1));
        fact[0] = 1;
        for (int i = 1; i <= MAXV; ++i) fact[i] = fact[i - 1] * i % MOD;
        invfact[MAXV] = modpow(fact[MAXV], MOD - 2);
        for (int i = MAXV; i > 0; --i) invfact[i - 1] = invfact[i] * i % MOD;
        for (int i = 1; i <= MAXV; ++i) {
            cnt[i][0] = 1;
            for (int j = 2 * i; j <= MAXV; j += i) {
                for (int k = 0; k < MAXB && cnt[i][k]; ++k) {
                    cnt[j][k + 1] = (cnt[j][k + 1] + cnt[i][k]) % MOD;
                }
            }
        }
    }
    
    long long modpow(long long a, long long e) {
        long long r = 1;
        a %= MOD;
        while (e > 0) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    }


    int idealArrays(int n, int maxValue) {
        long long ans = 0;
        for (int val = 1; val <= maxValue; ++val) {
            for (int bars = 0; bars <= min(n - 1, MAXB); ++bars) {
                if (!cnt[val][bars]) break;
                ans = (ans + cnt[val][bars] * comb(n - 1, bars)) % MOD;
            }
        }
        return ans;
    }
};