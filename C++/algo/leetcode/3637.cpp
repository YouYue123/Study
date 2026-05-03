// 3637. Trionic Array I [E]
// LeetCode trionic-array-i

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return false;
        for(int i = 1; i < n; i ++) {
            if(nums[i] <= nums[i - 1]) return false;
            for(int j = i + 1; j < n - 1; j ++) {
                if(nums[j] >= nums[j - 1]) break;
                bool isValid = true;
                for(int k = j + 1; k < n; k ++) {
                    if(nums[k] <= nums[k - 1]) {
                        isValid = false;
                        break;
                    }
                }
                if(isValid) {
                    // cout << i << " " << j << " " << endl;
                    return true;
                }
            }
        }
        return false;
    }
};