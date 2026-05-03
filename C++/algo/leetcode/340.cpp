// 340. Longest Substring with At Most K Distinct Characters [M]
// LeetCode longest-substring-with-at-most-k-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int count = 0;
        int left = 0, right = 0;
        unordered_map<char, int> freq;
        int ans = 0;
        while(right < s.size()) {
            freq[s[right]] += 1;
            if(freq[s[right]] == 1) count += 1;
            while(count > k) {
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