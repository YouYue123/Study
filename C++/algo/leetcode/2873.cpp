// 2873. Maximum Value of an Ordered Triplet I [E]
// LeetCode maximum-value-of-an-ordered-triplet-i

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxI = max(nums[0], nums[1]);
        long long maxPre = nums[0] - nums[1];
        long long ans = 0;
        for(int i = 2; i < nums.size(); i ++) {
            ans = max(ans, maxPre * nums[i]);
            maxPre = max(maxPre, maxI - nums[i]);
            maxI = max(maxI, (long long)nums[i]);
            // cout << " maxPre: " << maxPre << " maxI: " << maxI << endl;
        }
        return ans;
    }
};