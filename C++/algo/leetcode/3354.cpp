// 3354. Make Array Elements Equal to Zero [E]
// LeetCode make-array-elements-equal-to-zero

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n + 1);
        for(int i = 0 ; i < n; i ++) {
            presum[i + 1] = presum[i] + nums[i];
        }
        int ans = 0;
        for(int i = 0 ;i < nums.size(); i ++) {
            int front = presum[i];
            int back = presum[n] - presum[i + 1];
            // cout << i << " " << front << " " << nums[i] << " " << back << endl;
            if(nums[i] == 0) {
                int gap = abs(front - back);
                if(gap == 0) ans += 2;
                if(gap == 1) ans += 1;
            }
        }
        return ans;
    }
};