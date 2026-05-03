// 15. 3Sum [M]
// LeetCode 3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i ++) {
            int target = -nums[i];
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while(left < right) {
                int cur_sum = nums[left] + nums[right];
                if(cur_sum > target) {
                    right -= 1;
                } else if(cur_sum < target) {
                    left += 1;
                } else {
                    int cur_left = nums[left];
                    int cur_right = nums[right];
                    ans.push_back({nums[i], cur_left, cur_right});
                    while(left < right && cur_left == nums[left]) left += 1;
                    while(left < right && cur_right == nums[right]) right -= 1;
                }
            }
        }
        return ans;
    }
};