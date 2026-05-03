// 45. Jump Game II [M]
// LeetCode jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxSoFar = 0;
        int nextJump = 0;
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i ++) {
            maxSoFar = max(maxSoFar, nums[i] + i);
            if(nextJump == i) {
                nextJump = maxSoFar;
                ans += 1;
            }
        }
        return ans;
    }
};