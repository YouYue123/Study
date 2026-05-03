// 930. Binary Subarrays With Sum [M]
// LeetCode binary-subarrays-with-sum

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> dict;
        dict[0] = 1;
        for(int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            int target = sum - goal;
            ans += dict[target];
            dict[sum] += 1;
        }
        return ans;
    }
};