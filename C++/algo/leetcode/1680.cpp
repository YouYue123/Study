// 1680. Concatenation of Consecutive Binary Numbers [M]
// LeetCode concatenation-of-consecutive-binary-numbers

int MOD = 1e9 + 7;
class Solution {
public:
    int concatenatedBinary(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            int m = log2(i) + 1;
            for(int k = 0; k < m; k ++) {
                ans = (ans * 2) % MOD;
            }
            ans = (ans + i) % MOD;
            // cout << i << " " << m << endl;
        }
        return ans;
    }
};