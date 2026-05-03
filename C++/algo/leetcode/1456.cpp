// 1456. Maximum Number of Vowels in a Substring of Given Length [M]
// LeetCode maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0, right = 0;
        unordered_set<char> dict = {
           'a', 'e', 'i', 'o', 'u'
        };
        int vCount = 0;
        int ans = INT_MIN;
        while(right < s.size()) {
            char rc = s[right];
            if(dict.contains(rc)) vCount += 1;
            if(right - left + 1 > k) {
                char lc = s[left];
                if(dict.contains(lc)) vCount -= 1;
                left += 1;
            }
            // cout << left << " " << right << endl;
            ans = max(ans, vCount);
            right += 1;
        }
        return ans;
    }
};