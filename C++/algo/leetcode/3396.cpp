// 3396. Minimum Number of Operations to Make Elements in Array Distinct [E]
// LeetCode minimum-number-of-operations-to-make-elements-in-array-distinct

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int nonDistinctCount = 0;
        unordered_map<int, int> dict;
        for(int num : nums) {
            if(dict[num] == 1) nonDistinctCount += 1;
            dict[num] += 1;
        }
        int ans = 0;
        int i = 0;
        while(nonDistinctCount != 0) {
            int temp = i;
            while(i < nums.size() && i < temp + 3) {
                int num = nums[i];
                if(dict[num] == 2) nonDistinctCount -= 1;
                dict[num] -= 1;
                i += 1;
            } 
            ans += 1;
        }
        return ans;
    }
};