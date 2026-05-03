// 1018. Binary Prefix Divisible By 5 [E]
// LeetCode binary-prefix-divisible-by-5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        long long cur = 0;
        for(int num : nums) {
            cur = (2 * cur + num) % 5;
            ans.push_back(cur % 5 == 0);
        }
        return ans;
    }
};