// 2598. Smallest Missing Non-negative Integer After Operations [M]
// LeetCode smallest-missing-non-negative-integer-after-operations

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int ans = 0;
        unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] >= 0) dict[nums[i] % value] += 1;
            else {
                dict[(nums[i] % value + value) % value] += 1;
            }
        }
        while(true) {
            int target = ans % value;
            // cout << target << endl;
            if(!dict.contains(target) || dict[target] == 0) break;
            dict[target] -= 1;
            ans += 1;
        }
        return ans;
    }
};