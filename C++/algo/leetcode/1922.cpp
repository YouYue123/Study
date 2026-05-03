#include <bits/stdc++.h>
using namespace std;

// 1922. Count Good Numbers [M]
// LeetCode count-good-numbers

class Solution {
public:
    int MOD = 1000000007;
    long long binpow(long long a, long long b) {
        a %= MOD;
        long long res = 1;
        while (b > 0) {
            if (b % 2) res = res * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long oddCount = n / 2;
        long long evenCount = (n + 1) / 2;
        long long oddVal = binpow(4, oddCount);
        long long evenVal = binpow(5, evenCount);
        return (oddVal * evenVal) % MOD;;
    }
};