// 446. Arithmetic Slices II - Subsequence [H]
// LeetCode arithmetic-slices-ii-subsequence

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, unordered_map<long long, int>> dict;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < i; j ++) {
                long long diff = 1LL * nums[i] - nums[j];
                if(dict[j].contains(diff)) {
                    ans += dict[j][diff];
                    dict[i][diff] += dict[j][diff];
                }
                dict[i][diff] += 1;
            }
        }
        return ans;
    }
};