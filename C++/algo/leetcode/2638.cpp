#include <bits/stdc++.h>
using namespace std;

// 2638. Count the Number of K-Free Subsets [M]
// LeetCode count-the-number-of-k-free-subsets

class Solution {
public:
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> dict;
        for(int num : nums) dict[num % k].push_back(num);
        long long ans = 1;
        for(auto& [remainder, sortedNums] : dict) {
            int n = sortedNums.size();
            // for(int num : sortedNums) cout << num << " ";
            // cout << endl;
            vector memo(n, -1LL);
            auto dfs = [&] (this auto&& dfs, int i) -> long long {
                if(i == n) return 1;
                if(memo[i] != -1) return memo[i];
                long long ans = dfs(i + 1);
                if(i + 1 < n && sortedNums[i + 1] == sortedNums[i] + k) {
                    ans += dfs(i + 2);
                } else {
                    ans += dfs(i + 1);
                }
                return memo[i] = ans;
            };
            // cout << dfs(0) << endl;
            ans *= dfs(0);
        }
        return ans;
    }
};