// 3349. Adjacent Increasing Subarrays Detection I [E]
// LeetCode adjacent-increasing-subarrays-detection-i

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int cnt = 1, preCnt = 0, ans = 0;
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i] > nums[i - 1]) {
                cnt += 1;
            } else {
                preCnt = cnt;
                cnt = 1;
            }
            ans = max(ans, min(preCnt, cnt));
            ans = max(ans, cnt / 2);
        }
        return ans >= k;
    }
};