// 2654. Minimum Number of Operations to Make All Array Elements Equal to 1 [M]
// LeetCode minimum-number-of-operations-to-make-all-array-elements-equal-to-1

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int g = nums[0];
        int cnt = g == 1 ? 1 : 0;
        for(int i = 1; i < nums.size(); i ++) {
            g = std::gcd(g, nums[i]);
            if(nums[i] == 1) cnt += 1;
        }
        if(g > 1) return -1;
        if(cnt > 0) return nums.size() - cnt;
        int minLen = INT_MAX;
        for(int i = 0; i < nums.size(); i ++) {
            g = nums[i];
            for(int j = i + 1; j < nums.size(); j ++) {
                g = std::gcd(g, nums[j]);
                if(g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen - 1 + nums.size() - 1;
    }
};