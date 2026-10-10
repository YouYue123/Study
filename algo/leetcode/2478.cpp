#include <bits/stdc++.h>
using namespace std;

// 2478. Number of Beautiful Partitions [H]
// LeetCode number-of-beautiful-partitions

int MOD = 1e9 + 7;
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        unordered_set<char> primes = {
            '2', '3', '5', '7'
        };
        vector memo(n, vector(k + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int cnt) {
            if(cnt > k) return 0;
            if(i == n) return cnt == k ? 1 : 0;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            long long ans = 0;
            if(primes.contains(s[i])) {
                int maxJ = n - (k - (cnt + 1)) * minLength;
                for(int j = i + minLength - 1; j <= maxJ && j < n; j ++) {
                    if(!primes.contains(s[j])) {
                        ans = (ans + dfs(j + 1, cnt + 1)) % MOD;
                    }
                }
            }
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0);
    }
};