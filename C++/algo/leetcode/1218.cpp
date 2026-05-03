// 1218. Longest Arithmetic Subsequence of Given Difference [M]
// LeetCode longest-arithmetic-subsequence-of-given-difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> memo;
        int ans = 0;
        for(int num : arr) {
            if(memo.contains(num - difference)) memo[num] = memo[num - difference] + 1;
            else memo[num] = 1;
            ans = max(ans, memo[num]);
        }
        return ans;
    }
};