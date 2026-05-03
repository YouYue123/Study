// 961. N-Repeated Element in Size 2N Array [E]
// LeetCode n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int ans = 0, hp = 0;
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i] == nums[0]) return nums[i];
            if(hp == 0) {
                ans = nums[i];
                hp = 1;
            } else {       
                hp += (ans == nums[i] ? 1 : -1);
            }
        }
        return ans;
    }
};