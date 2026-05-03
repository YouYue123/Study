#include <bits/stdc++.h>
using namespace std;

// 474. Ones and Zeroes [M]
// LeetCode ones-and-zeroes

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> pairs;
        for(string& str: strs) {
            pair<int, int> p = {0, 0};
            for(char c : str) {
                if(c == '0') p.first += 1;
                else p.second += 1;
            }
            pairs.push_back(p);
        }
        vector memo(
            len,
            vector(
                m + 1,
                vector(n + 1, -1)
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int a, int b) {
            if(a > m || b > n) return INT_MIN;
            if(i >= len) return 0;
            if(memo[i][a][b] != -1) return memo[i][a][b];
            return memo[i][a][b] = max( 
                dfs(i + 1, a, b), 
                dfs(i + 1, a + pairs[i].first, b + pairs[i].second) + 1
            );
        };
        return dfs(0, 0, 0);
    }
};