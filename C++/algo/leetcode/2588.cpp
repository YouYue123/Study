// 2588. Count the Number of Beautiful Subarrays [M]
// LeetCode count-the-number-of-beautiful-subarrays

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // 4,  3,   1,  2, 4
        // 100,011,001,010, 100
        // 1110
        long long ans = 0;
        unordered_map<int, int> dict;
        dict[0] = 1;
        int sum = 0;
        for(int num : nums) {
            sum ^= num;
            ans += dict[sum];
            dict[sum] += 1;
        } 
        return ans;
    }
};