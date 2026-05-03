// 287. Find the Duplicate Number [M]
// LeetCode find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        for(int num : nums) {
            // cout << num << endl;
            int cur_num = abs(num);
            if(nums[cur_num] < 0) {
                ans = cur_num;
                break;
            }
            nums[cur_num] = -nums[cur_num];
        }

        return ans;
    }
};