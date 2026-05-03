// 940. Distinct Subsequences II [H]
// LeetCode distinct-subsequences-ii

int MOD = 1e9 + 7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int dict[26] = {};
        for(char c : s) {
            int sum = 0;
            for(int i = 0; i < 26; i ++) sum = (sum + dict[i]) % MOD;
            dict[c - 'a'] = sum + 1;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans = (ans + dict[i]) % MOD;
        }
        return ans;
    }
};