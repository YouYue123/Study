#include <bits/stdc++.h>
using namespace std;

// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum [M]
// LeetCode find-two-non-overlapping-sub-arrays-each-with-target-sum

class Solution {
public:
  int minSumOfLengths(std::vector<int>& arr, int target) {
        std::unordered_map<int, int> dict;
        dict[0] = -1;
        int sum = 0;
        std::vector<int> dp(arr.size() + 1, INT_MAX);
        int curMin = INT_MAX;
        int ans = INT_MAX; 
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            // cout << "i: " << i << endl;
            int comple = sum - target;
            if (dict.contains(comple)) {
                int prevIndex = dict[comple];
                int curLen = i - prevIndex;
                // cout << curLen << endl;
                curMin = std::min(curMin, curLen);
                if (dp[prevIndex + 1] != INT_MAX) ans = std::min(ans, dp[prevIndex + 1] + curLen);
            }
            dp[i + 1] = dp[i];
            dp[i + 1] = std::min(dp[i], curMin);            
            dict[sum] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};