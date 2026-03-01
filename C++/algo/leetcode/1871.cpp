#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool canReach(string s, int minJump, int maxJump) {
            int n = s.size();
            vector dp(n, 0);
            vector pre(n + 1, 0);
            dp[0] = 1;
            for(int i = 0 ;i < n; i ++) {
                if(i >= minJump && s[i] == '0') {
                    int left = max(0, i - maxJump);
                    int right = i - minJump;
                    if(pre[right + 1] - pre[left] > 0) {
                        dp[i] = 1;
                    }
                }
                pre[i + 1] = pre[i] + dp[i];
            }
            return dp[n - 1] == 1;
        }
    };