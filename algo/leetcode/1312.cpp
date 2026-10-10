#include <bits/stdc++.h>
using namespace std;

// 1312. Minimum Insertion Steps to Make a String Palindrome [H]
// LeetCode minimum-insertion-steps-to-make-a-string-palindrome

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i >= j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = INF;
            if(s[i] == s[j]) {
                ans = dfs(i + 1, j - 1);
            } else {
                ans = min(
                    dfs(i + 1, j) + 1, 
                    dfs(i, j - 1) + 1
                );
            }
            return memo[i][j] = ans;
        };
        // dfs(0, n - 1);
        // for(int i = 0; i < n; i ++) {
        //     for(int j = 0; j < n ; j ++) {
        //         cout << memo[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dfs(0, n - 1);
    }
};