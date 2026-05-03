// 3512. Minimum Operations to Make Array Sum Divisible by K [E]
// LeetCode minimum-operations-to-make-array-sum-divisible-by-k

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int num : nums) sum += num;
        return sum % k;
    }
};