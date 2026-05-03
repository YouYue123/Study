// 1995. Count Special Quadruplets [E]
// LeetCode count-special-quadruplets

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        //  nums[a] + nums[b] == nums[d] - nums[c]
        unordered_map<int, int> dict;
        int ans = 0;
        for(int b = 1; b < nums.size() - 2; b ++) {
            for(int a = 0; a < b; a ++) {
                int sum = nums[a] + nums[b];
                dict[sum] += 1;
            }
            int c = nums[b + 1];
            for(int d = b + 2; d < nums.size(); d ++) {
                int diff = nums[d] - c;
                if(diff >= 0) ans += dict[diff];
            }
        }
        return ans;
    }
};