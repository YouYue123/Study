// 3732. Maximum Product of Three Elements After One Replacement [M]
// LeetCode maximum-product-of-three-elements-after-one-replacement

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        long long maxEle = nums[nums.size() - 1];
        long long sMaxEle = nums[nums.size() - 2];
        long long minEle = nums[0];
        long long sMinEle = nums[1];
        return max({
           abs(maxEle * sMaxEle * 1e5),
           abs(maxEle * minEle * 1e5),
           abs(minEle * sMinEle * 1e5)
        });
    }
};