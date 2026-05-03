// 1031. Maximum Sum of Two Non-Overlapping Subarrays [M]
// LeetCode maximum-sum-of-two-non-overlapping-subarrays

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        unordered_map<int, int> maxSum1;
        unordered_map<int, int> maxSum2;
        int left = 0, right = 0, sum = 0;
        int ans = -1;
        while(right < nums.size()) {
            sum += nums[right];
            if(right - left + 1 == firstLen) {
                maxSum1[right] = max(maxSum1[right - 1], sum);
                sum -= nums[left];
                left += 1;
            }
            right += 1;
        }
        left = 0, right = 0, sum = 0;
        while(right < nums.size()) {
            sum += nums[right];
            if(right - left + 1 == secondLen) {
                maxSum2[right] = max(maxSum2[right - 1], sum);
                ans = max(ans, sum + maxSum1[right - secondLen]);
                sum -= nums[left];
                left += 1;
            }
            right += 1;
        }
        // for(int i = 0; i < nums.size(); i ++) {
        //     cout << maxSum1[i] << " " << maxSum2[i] << endl;
        // }
        left = 0, right = 0, sum = 0;
        while(right < nums.size()) {
            sum += nums[right];
            if(right - left + 1 == firstLen) {
                ans = max(ans, sum + maxSum2[right - firstLen]);
                sum -= nums[left];
                left += 1;
            }
            right += 1;
        }
        return ans;
    }
};