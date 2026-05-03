// 140. Word Break II [H]
// LeetCode word-break-ii

class Solution {
public:
    vector<string> ans;
    void dfs(string& s, vector<string>& wordDict, int i, string cur) {
        // cout << i << " " << cur << endl;
        if(i == s.size()) {
            cur.pop_back();
            ans.push_back(cur);
            return;
        };
        if(i > s.size()) return;
        for(string& word: wordDict) {
            int p1 = i;
            int p2 = 0;
            while(p1 < s.size() && p2 < word.size() && s[p1] == word[p2]) {
                p1 += 1;
                p2 += 1;
            }
            if(p2 == word.size()) dfs(s, wordDict, i + p2, cur + word + " ");
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dfs(s, wordDict, 0, "");
        return ans;
    }
};