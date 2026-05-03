#include <bits/stdc++.h>
using namespace std;

// 3556. Sum of Largest Prime Substrings [M]
// LeetCode sum-of-largest-prime-substrings

class Solution {
public:
    unordered_map<long, bool> memo;
    bool isPrime(long n) {
        if(memo.contains(n)) return memo[n];
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return memo[n] = false;
            }
        }
        return memo[n] = true;
    }
    long long sumOfLargestPrimes(string s) {
        set<long, greater<long>> set;
        for(int i = 0; i < s.size(); i ++) {
            for(int j = i; j < s.size(); j ++) {
                string cur = s.substr(i, j - i + 1);
                long long num = stol(cur);
                if(isPrime(num)) {
                    set.insert(num);
                }
            }
        }
        long long ans = 0;
        int count = 0;
        for(auto item : set) {
            if(count == 3) break;
            count += 1;
            ans += item;
        }
        return ans;
    }
};