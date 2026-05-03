// 214. Shortest Palindrome [H]
// LeetCode shortest-palindrome

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined_s = s + '#' + rev_s;
        cout << combined_s << endl;
        auto get_next = [&] (string& s) {
            int m = s.size();
            vector<int> next(m, 0);
            for(int i = 1, j = 0; i < m; i ++) {
                while(j > 0 && s[i] != s[j]) {
                    j = next[j - 1];
                }
                if(s[i] == s[j]) j += 1;
                next[i] = j;
            }
            return next;
        };
        auto next = get_next(combined_s);
        int maxLen = next.back();
        // cout << maxLen << endl;
        string add = s.substr(maxLen);
        reverse(add.begin(), add.end());
        return add + s;
        
    }
};