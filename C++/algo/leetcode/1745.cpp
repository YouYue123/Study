// 1745. Palindrome Partitioning IV [H]
// LeetCode palindrome-partitioning-iv

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector pMemo(n, vector(n, -1));
        auto isP = [&] (this auto&& dfs, int i, int j) -> bool {
            if(i >= j) return true;
            if(pMemo[i][j] != -1) return pMemo[i][j];
            bool ans = false;
            if(s[i] == s[j]) ans = dfs(i + 1, j - 1);
            return pMemo[i][j] = ans;
        };
        vector memo(n, vector(4, -1));
        auto dfs = [&] (this auto&& dfs, int i, int cnt) -> bool {
            if(cnt > 3) return false;
            if(i == n) return cnt == 3;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            bool ans = false;
            for(int j = i; j < n; j ++) {
                if(isP(i, j) && dfs(j + 1, cnt + 1)) {
                    ans = true;
                    break;
                }
            }
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0);
    }
};