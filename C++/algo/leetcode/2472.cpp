// 2472. Maximum Number of Non-overlapping Palindrome Substrings [H]
// LeetCode maximum-number-of-non-overlapping-palindrome-substrings

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector pMemo(n, vector(n, -1));
        auto isP = [&] (this auto&& dfs, int i, int j) {
            if(i >= j) return true;
            if(pMemo[i][j] != -1) return pMemo[i][j] == 1;
            bool ans = s[i] == s[j] && dfs(i + 1, j - 1);
            pMemo[i][j] = (ans ? 1 : 0);
            return ans;
        };

        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = dfs(i + 1);
            for(int j = i + k - 1; j < n; j ++) {
                if(isP(i, j)) {
                    ans = max(
                        ans,
                        dfs(j + 1) + 1
                    );
                }
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};