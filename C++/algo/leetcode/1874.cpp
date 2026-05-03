// 1874. Minimize Product Sum of Two Arrays [M]
// LeetCode minimize-product-sum-of-two-arrays

class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end(), greater<>());
        sort(nums2.begin(), nums2.end());
        int ans = 0;
        for(int i = 0; i < nums1.size(); i ++) {
            ans += nums1[i] * nums2[i];
        }
        return ans;
    }
};