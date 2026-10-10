#include <bits/stdc++.h>
using namespace std;

// 1884. Egg Drop With 2 Eggs and N Floors [M]
// LeetCode egg-drop-with-2-eggs-and-n-floors

class Solution {
public:
    int twoEggDrop(int n) {
        
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int sum) {
            if(i + sum >= n) return 0;
            if(memo[i][sum] != -1) return memo[i][sum];
            return memo[i][sum] = 1 + dfs(i + 1, sum + i);
        };

        return dfs(0, 0);
    }
};