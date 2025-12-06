#include <bits/stdc++.h>
using namespace std;
// LC: 3500
// https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays/
class Solution {
    public:
        long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
            int n = nums.size();
            vector numPreSum(n + 1, 0LL);
            vector costPreSum(n + 1, 0LL);
            for(int i = 0; i < n; i ++) {
                numPreSum[i + 1] = numPreSum[i] + nums[i];
                costPreSum[i + 1] = costPreSum[i] + cost[i];
            }
            vector memo(n, -1LL);
            auto dfs = [&] (this auto&& dfs, int i) {
                if(i == n) return 0LL;
                if(memo[i] != -1LL) return memo[i];
                long long ans = LONG_LONG_MAX;
                for(int j = i; j < n; j ++) {
                    // Abel's summation formula
                    // auto firstPart = (numPreSum[j + 1] + k * cnt) * (costPreSum[j + 1] - costPreSum[i]);
                    auto firstPart = numPreSum[j + 1] * (costPreSum[j + 1] - costPreSum[i]) + k * (costPreSum[n] - costPreSum[i]);
                    // numPreSum[j + 1] * (costPreSum[j + 1] - costPreSum[i]) + 
                    // k * cnt * (costPreSum[j + 1] - costPreSum[i]) 
                    // --> k * (costPresum[n] - costPresum[i])
                    // cout << "first part: " << firstPart << endl;
                    ans = min(ans, firstPart + dfs(j + 1));
                }
                return memo[i] = ans;
            };
            return dfs(0);
        }
    };