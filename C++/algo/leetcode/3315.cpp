// 3315. Construct the Minimum Bitwise Array II [M]
// LeetCode construct-the-minimum-bitwise-array-ii

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums) {
            if(num % 2 == 0) ans.push_back(-1);
            else {
                int t = ~num;
                int lowbit = t &(-t);
                ans.push_back(num ^ (lowbit >> 1));
            }
        }
        return ans;
    }
};