#include <bits/stdc++.h>
using namespace std;

// 368. Largest Divisible Subset [M]
// LeetCode largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> nxt(n, -1);
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = 0;
            for(int j = i + 1; j < n; j ++) {
                if(nums[j] % nums[i] == 0) {
                    int cur = dfs(j) + 1;
                    if(cur > ans) {
                        ans = cur;
                        nxt[i] = j;
                    }
                }
            }
            return memo[i] = ans;
        };
        int maxLen = 0, maxI = 0;
        for(int i = 0; i < n; i ++) {
            if(dfs(i) > maxLen) {
                maxLen = dfs(i);
                maxI = i;
            }
        }
        vector<int> ans;
        for(int i = maxI; i >= 0; i = nxt[i]) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};