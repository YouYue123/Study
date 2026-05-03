// 3563. Lexicographically Smallest String After Adjacent Removals [H]
// LeetCode lexicographically-smallest-string-after-adjacent-removals

class Solution {
public:
    bool isAdj(char a, char b) {
        return abs(a - b) == 1 || abs(a - b) == 25;
    }

    string lexicographicallySmallestString(string s) {
        int n = s.size();
        vector<vector<string>> dp(n + 1, vector<string>(n + 1, ""));
        
        for (int len = 1; len <= n; len++) {  // 枚举子串长度
            for (int i = 0; i + len <= n; i++) {  // 枚举子串起点
                int j = i + len;  // 子串终点
                string ans = s[i] + dp[i + 1][j];  // 默认不删除 s[i]
                
                for (int k = i + 1; k < j; k++) {  // 枚举可能的删除点 k
                    if (isAdj(s[i], s[k]) && dp[i + 1][k] == "") {
                        // 如果 s[i] 和 s[k] 可以删除，且 s[i+1...k-1] 可以完全删除
                        ans = min(ans, dp[k + 1][j]);  // 更新最小字典序
                    }
                }
                
                dp[i][j] = ans;  // 记录最优解
            }
        }
        
        return dp[0][n];  // 返回整个字符串的最优解
    }
};