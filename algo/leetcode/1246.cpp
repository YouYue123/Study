#include <bits/stdc++.h>
using namespace std;

// 1246. Palindrome Removal [H]
// LeetCode palindrome-removal

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == j) return 1;
            if(i > j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 1 + dfs(i + 1, j);
            if(arr[i] == arr[i + 1]) {
                ans = min(ans, dfs(i + 2, j) + 1);
            }
            for(int k = i + 2; k <= j; k ++) {
                if(arr[i] == arr[k]) {
                    ans = min(ans, dfs(i + 1, k - 1) + dfs(k + 1, j));
                }
            }
            return memo[i][j] = ans;
        };
        return dfs(0, n - 1);
    }
};