// 387. First Unique Character in a String [E]
// LeetCode first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int freq[26] = {0};
        for(char c :s) freq[c - 'a'] += 1;
        for(int i = 0; i < n; i ++) {
            if(freq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};