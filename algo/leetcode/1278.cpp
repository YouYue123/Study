#include <bits/stdc++.h>
using namespace std;

// 1278. Palindrome Partitioning III [H]
// LeetCode palindrome-partitioning-iii

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector pMemo(n, vector(n, -1));
        auto calc = [&] (this auto&& dfs, int i, int j) {
            if(i >= j) return 0;
            if(pMemo[i][j] != -1) return pMemo[i][j];
            int ans = dfs(i + 1, j - 1);
            if(s[i] != s[j]) ans += 1;
            return pMemo[i][j] = ans;
        };
        vector memo(n, vector(k + 1, -1));
        auto dfs  = [&] (this auto&& dfs, int i, int cnt) {
            if(i == n) return cnt == k ? 0 : INT_MAX;
            if(cnt >= k) return INT_MAX;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            int ans = INT_MAX;
            for(int j = i; j < n; j ++) {
                int curOps = calc(i, j);
                int remain = dfs(j + 1, cnt + 1);
                // cout << i << " " << j << " " << remain << " " << curOps << endl;
                if(remain != INT_MAX) ans = min(ans, remain + curOps);
            } 
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0);
    }
};