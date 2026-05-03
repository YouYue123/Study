// 809. Expressive Words [M]
// LeetCode expressive-words

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        // vector<int> count;
        // int left = 0;
        // int right =0;
        // while(right < s.size()) {
        //     while(s[right] == s[left]) right += 1;
        //     count.push_back
        // }
        for(string word: words) {
            int i = 0;
            int j = 0;
            // cout << word << endl;
            bool isFound = true;
            while(i < s.size() && j < word.size()) {
                int sCount = 0;
                int wCount = 0;
                if(s[i] != word[j]) {
                    isFound = false;
                    break;
                };
                while(s[i] == word[j]) {
                    sCount += 1;
                    i += 1;
                }
                char prev = word[j];
                while(word[j] == prev)  {
                    wCount += 1;
                    j += 1;
                }
                // cout << "i " << i << " j " << j << endl;
                // cout << "sCount " << sCount << " wCount " << wCount << endl;
                if((sCount > wCount && sCount < 3) || wCount > sCount) {
                    isFound = false;
                    break;
                }
            }
            if (isFound && i == s.size() && j == word.size()) {
                // cout << word << " is good" << endl;
                ans += 1;
            }
        }
        return ans;
    }
};