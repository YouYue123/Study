#include <bits/stdc++.h>
using namespace std;

// 96. Unique Binary Search Trees [M]
// LeetCode unique-binary-search-trees

class Solution {
public:
    int numTrees(int n) {
        vector memo(n + 1, vector(n + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i >= j) return 1;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            for(int k = i; k <= j; k ++) {
                int leftCnt = dfs(i, k - 1);
                int rightCnt = dfs(k + 1, j);
                ans += leftCnt * rightCnt;
            }
            return memo[i][j] = ans;
        };

        return dfs(1, n);
    }
};