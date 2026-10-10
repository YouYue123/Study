#include <bits/stdc++.h>
using namespace std;

// 1411. Number of Ways to Paint N × 3 Grid [H]
// LeetCode number-of-ways-to-paint-n-3-grid

int MOD = 1e9 + 7;
class Solution {
public:
    int numOfWays(int n) {
        // color state: r 00, y 01, g 10
        // rowState sample: rgy 001001 
        unordered_map<int ,int> memo; 
        auto dfs = [&] (this auto&& dfs, int i, int j, int preState, int curState) {
            if(i == n) return 1;
            if(j == 3) return dfs(i + 1, 0, curState, 0);
            int key = curState | (preState << 6) | (j << 12) | (i << 14);
            if(memo.contains(key)) return memo[key];
            int ans = 0;
            for(int c = 0; c < 3; c ++) {
                bool isSameAsLastRow = i > 0 && (preState >> (j * 2) & 3) == c;
                bool isSameAsLastCol = j > 0 && (curState >> ((j - 1) * 2) & 3) == c;
                if(isSameAsLastRow || isSameAsLastCol) continue;
                ans = (ans + dfs(i, j + 1, preState, curState | (c << (j * 2)))) % MOD;
            }
            return memo[key] = ans;
        };
        return dfs(0, 0, 0, 0);
    } 
};