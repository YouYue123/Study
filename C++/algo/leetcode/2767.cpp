#include <bits/stdc++.h>
using namespace std;

// 2767. Partition String Into Minimum Beautiful Substrings [M]
// LeetCode partition-string-into-minimum-beautiful-substrings

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        long long maxFive = pow(5LL, 10LL);
        int n = s.size();
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i < 0) return 0;
            if(s[i] == '0') return INT_MAX / 2;
            if(memo[i] != -1) return memo[i];
            int ans = dfs(i - 1) + 1;
            long long cur = 1;
            for(int j = i - 1; j >= 0; j --) {
                cur += (s[j] - '0') * pow(2, i - j);
                if(s[j] == '0') continue;
                if(maxFive % cur == 0) ans = min(ans, dfs(j - 1) + 1);
            }
            return memo[i] = ans;
        };
        return dfs(n - 1) >= INT_MAX / 2 ? -1 : dfs(n - 1);
    }
};