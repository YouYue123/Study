// 2962. Count Subarrays Where Max Element Appears at Least K Times [M]
// LeetCode count-subarrays-where-max-element-appears-at-least-k-times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxEle = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        long long ans = 0;
        while(right < nums.size()) {
            if(nums[right] == maxEle) cnt += 1;
            while(cnt == k) {
                if(nums[left] == maxEle) cnt -= 1;
                left += 1;
            }
            if(cnt == k - 1) ans += left;
            right += 1;
        }
        return ans;
    }
};