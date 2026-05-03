#include <bits/stdc++.h>
using namespace std;

// 132. Palindrome Partitioning II [H]
// LeetCode palindrome-partitioning-ii

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector isPal(n, vector<int>(n, -1));
        auto isP = [&](this auto&& dfs, int l, int r) -> bool {
            if(l >= r) return true;
            if(isPal[l][r] != -1) return isPal[l][r];
            return s[l] == s[r] && dfs(l + 1, r - 1);
        };
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int r) {
            if(isP(0, r)) return 0;
            if(memo[r] != -1) return memo[r];
            int ans = INT_MAX / 2;
            for(int l = 1; l <= r; l ++) {
                if(isP(l, r)) {
                    ans = min(ans, dfs(l - 1) + 1);
                }
            }
            return memo[r] = ans;
        };
        return dfs(n - 1);
    }
};