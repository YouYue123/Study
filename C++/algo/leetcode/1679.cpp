// 1679. Max Number of K-Sum Pairs [M]
// LeetCode max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        int ans = 0;
        for(int num : nums) {
            int comple = k - num;
            if(dict[comple] > 0) {
                ans += 1;
                dict[comple] -= 1;
            } else {
                dict[num] += 1;
            }
        }
        return ans;
    }
};