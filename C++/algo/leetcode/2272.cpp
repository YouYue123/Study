// 2272. Substring With Largest Variance [H]
// LeetCode substring-with-largest-variance

class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        int ans = 0;
        int memo[n][4];
        for(int i = 0; i < 26; i ++) {
            for(int j = 0; j < 26; j ++) {
                char t1 = 'a' + i, t2 = 'a' + j;
                if(t1 == t2) continue;
                memset(memo, -1, sizeof(memo));
                // cout << t1 << " " << t2 << endl;
                auto dfs = [&] (this auto&& dfs, int i, int state) {
                    if(i == n) return state == 3 ? 0 : INT_MIN / 2;
                    if(memo[i][state] != -1) return memo[i][state];
                    int ans = INT_MIN / 2;
                    if(state == 0) {
                        ans = dfs(i + 1, 0);
                        if(s[i] == t1) ans = max(ans, dfs(i + 1, 1) + 1);
                        else if(s[i] == t2) ans = max(ans, dfs(i + 1, 2) - 1);
                    } else if(state == 1) {
                        if(s[i] == t1) ans = dfs(i + 1, 1) + 1;
                        else if(s[i] == t2) ans = dfs(i + 1, 3) - 1;
                        else ans = dfs(i + 1, 1);
                    } else if(state == 2) {
                        if(s[i] == t1) ans = dfs(i + 1, 3) + 1;
                        else if(s[i] == t2) ans = dfs(i + 1, 2) - 1;
                        else ans = dfs(i + 1, 2); 
                    } else if(state == 3) {
                        ans = 0;
                        if(s[i] == t1) ans = max(ans, dfs(i + 1, 3) + 1);
                        else if(s[i] == t2) ans = max(ans, dfs(i + 1, 3) - 1);
                        else ans = max(ans, dfs(i + 1, 3));
                    }
                    return memo[i][state] = ans;
                };
                // cout << dfs(0, 0) << endl;
                ans = max(ans, dfs(0, 0));
            }
        }
        return ans;
    }
};