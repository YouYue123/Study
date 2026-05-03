// 448. Find All Numbers Disappeared in an Array [E]
// LeetCode find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i ++) {
            // int j = i;
            int cur = nums[i];
            while(cur != nums[cur - 1]) {
                int temp = nums[cur - 1];
                nums[cur - 1] = cur;
                cur = temp;
                // cout << temp << endl;
            }
        }
        // for(int num : nums) cout << num << " ";
        // cout << endl;
        for(int i = 0; i < n; i ++) {
            if(nums[i] != i + 1) ans.push_back(i + 1);
        }
        return ans;
    }
};