#include <bits/stdc++.h>
using namespace std;

// 2134. Minimum Swaps to Group All 1's Together II [M]
// LeetCode minimum-swaps-to-group-all-1s-together-ii

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int oneCount = 0;
        for(int num : nums) oneCount += num == 1;
        int left = 0, right = 0;
        int windowOneCnt = 0;
        int ans = INT_MAX;
        while(left < nums.size()) {
            windowOneCnt += nums[right % nums.size()] == 1;
            if(right - left + 1 > oneCount) {
                windowOneCnt -= nums[left] == 1;
                left += 1;
            }
            if(right - left + 1 == oneCount) {
                ans = min(ans, right - left + 1 - windowOneCnt);
            }
            right += 1;
        }
        return ans;
    }
};