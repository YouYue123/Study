// 678. Valid Parenthesis String [M]
// LeetCode valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector memo(
            n,
            vector(n, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int left_cnt) -> bool {
            if(left_cnt < 0) return false;
            if(i == n) return left_cnt == 0;
            if(memo[i][left_cnt] != -1) return memo[i][left_cnt] == 1;
            bool ans = false;
            if(s[i] == '(') {
                ans = dfs(i + 1, left_cnt + 1);
            } else if(s[i] == '*') {
                ans = dfs(i + 1, left_cnt + 1) || dfs(i + 1, left_cnt - 1) || dfs(i + 1, left_cnt);
            } else if(s[i] == ')') {
                ans = dfs(i + 1, left_cnt - 1);
            }
            memo[i][left_cnt] = (ans ? 1 : 0);
            return ans;
        };
        return dfs(0, 0);
    }
};