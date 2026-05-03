// 3724. Minimum Operations to Transform Array [M]
// LeetCode minimum-operations-to-transform-array

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int minDiff = INT_MAX;
        long long ans = 0;
        int last = nums2[nums2.size() - 1];
        for(int i = 0; i < nums1.size(); i ++) {
            ans += abs(nums1[i] - nums2[i]);
            int nums1Diff = abs(nums1[i] - last);
            int nums2Diff = abs(nums2[i] - last);
            minDiff = min({ minDiff, nums1Diff, nums2Diff });
            if(nums1[i] >= last && nums2[i] <= last) minDiff = 0;
            if(nums1[i] <= last && nums2[i] >= last) minDiff = 0;
        }
        ans += 1 + minDiff;
        return ans;
    }
};