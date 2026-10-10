#include <bits/stdc++.h>
using namespace std;

// 2430. Maximum Deletions on a String [H]
// LeetCode maximum-deletions-on-a-string

class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        vector lcp(n + 1, vector(n + 1, 0));
        for(int i = n - 1; i >= 0; i --) {
            for(int j = n - 1; j >= 0; j--) {
                if(s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
        vector memo(n, -1);
        auto dfs = [&](this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = 1;
            for(int j = i; j < n; j ++) {
                int len = j - i + 1;
                if(i + 2 * len - 1 >= n) break;
                if(lcp[i][i + len] >= len) ans = max(ans, dfs(j + 1) + 1);
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};