#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        vector memo(r + 1, vector(2, 0LL));
        int len = r - l + 1;
        for (int k = l; k <= r; k++) {
            for (int state = 0; state <= 1; state++) {
                memo[k][state] = 1;
            }
        }
        // state == 0:  Σ_{k<prev}  memo[i+1][k][1]
        // state == 1:  Σ_{k>prev}  memo[i+1][k][0] 
        // s_0[v] = Σ_{k≤v} memo[i+1][k][0]
        // s_1[v] = Σ_{k≤v} memo[i+1][k][1] 
        vector<int> s_0(r + 1), s_1(r + 1);
        for (int i = n - 1; i >= 1; i--) {
            for(int k = l; k <= r; k ++) {
                s_0[k] = (s_0[k - 1] + memo[k][0]) % MOD;
                s_1[k] = (s_1[k - 1] + memo[k][1]) % MOD;
            }
            for (int k = l; k <= r; k++) {
                int pre_s1 = s_1[k - 1];
                int suf_s0 = (s_0[r] - s_0[k] + MOD) % MOD;
                memo[k][0] = pre_s1;
                memo[k][1] = suf_s0;
            }
        }

        int ans = 0;
        for (int first = l; first <= r; first++) {
            ans = (ans + memo[first][0] + memo[first][1]) % MOD;
        }
        return ans;
    }
};