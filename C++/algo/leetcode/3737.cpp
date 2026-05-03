// 3737. Count Subarrays With Majority Element I [M]
// LeetCode count-subarrays-with-majority-element-i

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++) {
            int cnt = 0;
            for (int j = i; j < nums.size(); j ++) {
                if(nums[j] == target) cnt += 1;
                if(cnt > (j - i + 1) / 2) ans += 1;
            }
        }
        return ans;
    }
};