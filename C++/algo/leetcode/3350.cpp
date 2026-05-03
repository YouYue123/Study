// 3350. Adjacent Increasing Subarrays Detection II [M]
// LeetCode adjacent-increasing-subarrays-detection-ii

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        auto isValid = [&] (int k) -> bool{
            int cnt = 1;
            int preCnt = 0;
            int ans = 0;
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
        };
        long long left = 0, right = nums.size();
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(isValid(mid)) {
                // cout << mid << " " << isValid(mid) << endl;
                left = mid + 1;
            } else {
                // cout << mid << " " << isValid(mid) << endl;
                right = mid;
            }
        }
        return left - 1;
    }
};