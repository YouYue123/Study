#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n, 0);
        vector<long long> pre(n + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i ++) {
            if(i >= delay) {
                int right = i - delay;
                int left = i - forget + 1;
                dp[i] = (pre[right + 1] - pre[max(0, left)] + MOD) % MOD;
            }
            pre[i + 1] = pre[i] + dp[i] ;
        }
        return (pre[n] - pre[n - forget]) % MOD;
    }
};