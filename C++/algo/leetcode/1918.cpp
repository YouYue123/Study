// 1918. Kth Smallest Subarray Sum [M]
// LeetCode kth-smallest-subarray-sum

class Solution {
public:
    bool isValid(vector<int>& nums, int target , int k) {
        int count = 0;
        int sum = 0;
        int left = 0, right = 0;
        while(right < nums.size()) {
            sum += nums[right];
            while(sum > target) {
                sum -= nums[left];
                left += 1;
            }
            count += right - left + 1;
            right += 1;
        }
        return count >= k; 
    }
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int left = *min_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};