// 1216. Valid Palindrome III [H]
// LeetCode valid-palindrome-iii

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i > j) return 0;
            // cout << i << " " << j << " " << cnt << endl;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            if(s[i] != s[j]) {
                ans = min(
                    dfs(i + 1, j) + 1,
                    dfs(i, j - 1) + 1
                );
            } else {
                ans = dfs(i + 1, j - 1);
            }
            return memo[i][j] = ans;
        };
        return dfs(0, n - 1) <= k;
    }
};