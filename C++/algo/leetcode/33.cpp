// 33. Search in Rotated Sorted Array [M]
// LeetCode search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = -1, right = n;
        auto isValid = [&] (int mid) {
            if(mid < 0) return true;
            if(mid >= n) return false;
            if(nums[0] <= nums[mid]) {
                return target >= nums[0] && target <= nums[mid];
            } else {
                return !(target >= nums[mid] && target <= nums[n - 1]);
            }
        };
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(mid >= 0 && mid < n && nums[mid] == target) return mid;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (right >= 0 && right < n && nums[right] == target) return right;
        return -1;
    }
};