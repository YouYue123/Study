// 1877. Minimize Maximum Pair Sum in Array [M]
// LeetCode minimize-maximum-pair-sum-in-array

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size() - 1;
        int curMax = -INF;
        while(s < e) {
            curMax = max(curMax, nums[e] + nums[s]);
            s += 1;
            e -= 1;
        }
        return curMax;
    }
};