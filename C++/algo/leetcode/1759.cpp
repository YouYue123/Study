// 1759. Count Number of Homogenous Substrings [M]
// LeetCode count-number-of-homogenous-substrings

class Solution {
public:
    int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int left = 0, right = 0;
        unordered_map<int, int> dict;
        int ans = 0;
        while(left < s.size()) {
            char leftC = s[left];
            while(right < s.size() && leftC == s[right]) {
                dict[s[right]] += 1;
                ans = (ans + dict[s[right]] % MOD) % MOD;
                right += 1;
            }
            dict[s[left]] -= 1;
            left += 1;
        }
        return ans;
    }
};