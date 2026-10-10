#include <bits/stdc++.h>
using namespace std;

// 2968. Apply Operations to Maximize Frequency Score [H]
// LeetCode apply-operations-to-maximize-frequency-score

class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int n = nums.size();
        vector<long long> presum(n + 1, 0);
        // cout << "123123" << endl;
        for(int i = 1 ; i <= n; i ++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        // cout << "werewr" << endl;
        int ans = INT_MIN;
        auto calc = [&](int left, int right, int medianIdx) {
            // cout << left << " " << right << " " << medianIdx << endl;
            long long target = nums[medianIdx];
            // from left to medianIdx - 1
            int leftCnt = medianIdx - left;
            long long pre = target * leftCnt - (presum[medianIdx] - presum[left]);
            // from medianIdx to right
            int rightCnt = right - medianIdx  + 1;
            long long post = (presum[right + 1] - presum[medianIdx]) - target * rightCnt;
            return pre + post; 
        };
        while(right < nums.size()) {
            while(calc(left, right, (left + right) / 2) > k) {
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};