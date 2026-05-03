#include <bits/stdc++.h>
using namespace std;

// 1043. Partition Array for Maximum Sum [M]
// LeetCode partition-array-for-maximum-sum

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = 0;
            int curMax = arr[i];
            for(int j = i; j < i + k; j ++) {
                if(j >= n) break;
                curMax = max(curMax, arr[j]);
                ans = max(
                    ans,
                    curMax * (j - i + 1) + dfs(j + 1)  
                );
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};