// 1092. Shortest Common Supersequence  [H]
// LeetCode shortest-common-supersequence

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector memo(
            n + 1,
            vector<int>(
                m + 1,
                -1
            )
        );
        auto dfs = [&] (this auto&& dfs , int i, int j) -> int {
            if(i >= n && j >= m) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            if(i >= n) {
                ans = 1 + dfs(i, j + 1);
            } else if(j >= m) {
                ans = 1 + dfs(i + 1, j);
            } else {
                if(str1[i] == str2[j]) {
                    ans = 1 + dfs(i + 1, j + 1);
                } else {
                    ans = min(
                        dfs(i + 1, j) + 1,
                        dfs(i, j + 1) + 1
                    );
                }
            }
            return memo[i][j] = ans;
        };
        dfs(0, 0);
        string ans = "";
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(str1[i] == str2[j]) {
                ans.push_back(str1[i]); i += 1; j += 1;
            } else if(memo[i+1][j] <= memo[i][j + 1]) {
                // Choose the shorter one
                ans.push_back(str1[i]); i += 1;
            } else {
                ans.push_back(str2[j]); j += 1;
            }
        }
        while(i < n) {
            ans.push_back(str1[i]); i += 1;
        }
        while(j < m) {
            ans.push_back(str2[j]); j += 1;
        }
        return ans;
    }
};