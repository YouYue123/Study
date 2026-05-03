// 1081. Smallest Subsequence of Distinct Characters [M]
// LeetCode smallest-subsequence-of-distinct-characters

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        int cnt[26];
        bool visited[26];
        for(int i = 0 ; i < n; i ++) cnt[s[i] - 'a'] += 1;
        string ans = "";
        for(char c : s) {
            if(!visited[c - 'a']) {
                while(!ans.empty() && ans.back() > c && cnt[ans.back() - 'a'] > 0) {
                    visited[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                ans.push_back(c);
                visited[c - 'a'] = true;
            }
            cnt[c - 'a'] -= 1;
            // cout << ans << endl;
        }
        return ans;
    }
};