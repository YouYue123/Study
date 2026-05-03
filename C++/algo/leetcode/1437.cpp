// 1437. Check If All 1's Are at Least Length K Places Away [E]
// LeetCode check-if-all-1s-are-at-least-length-k-places-away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastPos = -1;
        for(int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            if(num == 1) {
                if(lastPos != -1 && i - lastPos - 1 < k) return false;
                lastPos = i;
            }
        }
        return true;
    }
};