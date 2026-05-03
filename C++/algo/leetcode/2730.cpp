// 2730. Find the Longest Semi-Repetitive Substring [M]
// LeetCode find-the-longest-semi-repetitive-substring

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int count = 0;
        int left = 0, right = 0;
        int ans = 0;
        while(right < s.size()) {
            if(right != left && s[right - 1] == s[right]) count += 1;
            while(count > 1) {
                if(s[left + 1] == s[left]) count -= 1;
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};