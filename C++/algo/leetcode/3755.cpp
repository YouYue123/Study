// 3755. Find Maximum Balanced XOR Subarray Length [M]
// LeetCode find-maximum-balanced-xor-subarray-length

class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long ,int> firstOcc;
        int OFFSET = n;
        int xorSum = 0, balance = 0, ans = 0;
        long initialKey = ((long long) xorSum <<32) | (balance + OFFSET);
        firstOcc[initialKey] = -1;
        for(int i = 0; i < n; i ++) {
            xorSum ^= nums[i];
            if(nums[i] % 2 == 1) balance += 1;
            else balance -= 1;
            long long key = (long long) xorSum * (2LL * n + 1) + (balance + OFFSET);
            if(firstOcc.contains(key)) {
                ans = max(ans, i - firstOcc[key]);
            } else {
                firstOcc[key] = i;
            }
        }
        return ans;
    }
};