// 2831. Find the Longest Equal Subarray [M]
// LeetCode find-the-longest-equal-subarray

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int maxFreq = 0, left = 0, right = 0;
        unordered_map<int, int> count;
        int ans = 0;
        while(right < nums.size()) {
            count[nums[right]] += 1;
            maxFreq = max(maxFreq, count[nums[right]]);
            while(right - left + 1 - maxFreq > k) {
                count[nums[left]] -= 1;
                left += 1;
            }
            right += 1;
        }
        return maxFreq;
    }
};