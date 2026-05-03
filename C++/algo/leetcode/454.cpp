// 454. 4Sum II [M]
// LeetCode 4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        unordered_map<int ,int >dict;
        for(int num1 : nums1) {
            for(int num2 : nums2) {
                dict[num1 + num2] += 1;
            }
        } 
        for(int num3 : nums3) {
            for(int num4 : nums4) {
                int comple = -num3 - num4;
                ans += dict[comple];
            }
        }
        return ans;
    }
};