// 424. Longest Repeating Character Replacement [M]
// LeetCode longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int freq[26] = { 0 };
        int left = 0, right = 0;
        int maxFreq = 0;
        int ans = 0;
        while(right < n) {
            freq[s[right] - 'A'] += 1;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            while(right - left + 1 > maxFreq + k) {
                freq[s[left] - 'A'] -= 1;
                left += 1;
                int newMaxFreq = 0;
                for(int f : freq) {
                    newMaxFreq = max(newMaxFreq, f);
                }
                maxFreq = newMaxFreq;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};