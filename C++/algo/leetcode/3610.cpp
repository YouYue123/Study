#include <bits/stdc++.h>
using namespace std;

// 3610. Minimum Number of Primes to Sum to Target [M]
// LeetCode minimum-number-of-primes-to-sum-to-target

const int MAX_N= 1000;
bool composite[MAX_N + 1];
void sieve_primes() {
    composite[1] = true;
    for(int p = 2; p * p <= MAX_N; p ++) {
        if(!composite[p]) {
            for(int mult = p * p; mult <= MAX_N; mult += p) {
                composite[mult] = true;
            }
        }
    }
}
vector<int> primes;

class Solution {
public:
    int minNumberOfPrimes(int n, int m) {
        if (primes.empty()) {
            sieve_primes();
            for (int i = 2; i <= MAX_N; i++) {
                if (!composite[i]) {
                    primes.push_back(i);
                }
            }
        }
        int actualM = min(m, (int)primes.size());

        vector memo(
            actualM + 1,
            vector(n + 1, -1)
        );
        auto dfs = [&](this auto&& dfs, int i, int target) {
            if (target < 0) return INT_MAX;
            if (i < 0) return target == 0 ? 0 : INT_MAX;
            
            if (memo[i][target] != -1) return memo[i][target];
            int ans = dfs(i - 1, target);
            if(target >= primes[i]) {
                int choose = dfs(i, target - primes[i]);
                if (choose < INT_MAX) {
                    ans = min(ans, choose + 1);
                }
            }
            return memo[i][target] = ans;
        };
        int ans = dfs(actualM - 1, n);
        return ans == INT_MAX ? -1 : ans;
    }
};