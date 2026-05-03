#include <bits/stdc++.h>
using namespace std;

// 91. Decode Ways [M]
// LeetCode decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 1;
            if(s[i] == '0') return 0;
            if(memo[i] != -1) return memo[i];
            int ans = dfs(i + 1);
            if(s[i] == '1') {
                if(i + 1 < n) ans += dfs(i + 2);
            }  
            if(s[i] == '2') {
                if(i + 1 < n && s[i + 1] >= '0' && s[i + 1] <= '6') ans += dfs(i + 2); 
            } 
            return memo[i] = ans;
        };
        return dfs(0);
    }
};