// 159. Longest Substring with At Most Two Distinct Characters [M]
// LeetCode longest-substring-with-at-most-two-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> freq;
        int count = 0;
        int ans = 0;
        while(right < s.size()) {
            freq[s[right]] += 1;
            if(freq[s[right]] == 1) count += 1;
            while(count > 2) {
                freq[s[left]] -= 1;
                if(freq[s[left]] == 0) count -= 1;
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};