// 2489. Number of Substrings With Fixed Ratio [M]
// LeetCode number-of-substrings-with-fixed-ratio

class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        unordered_map<long long, int> dict;
        dict[0] = 1; 
        long long zeroSum = 0, oneSum = 0;
        long long ans = 0;
        for (char c : s) {
            if (c == '0') zeroSum++;
            else oneSum++;
            long long key = zeroSum * num2 - oneSum * num1;
            ans += dict[key];
            dict[key]++;
        }
        return ans;
    }
};