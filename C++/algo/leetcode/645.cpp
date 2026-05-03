// 645. Set Mismatch [E]
// LeetCode set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> dict;
        long long n = nums.size();
        long long dup = 0;
        long long sum = 0;
        for(int num : nums) {
            if(dict.contains(num)) dup = num;
            dict.insert(num);
            sum += num;
        }
        return {
            (int)dup,
            (int)(((1 + n) * n / 2 - sum) + dup)
        };
    }
};