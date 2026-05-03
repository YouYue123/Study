// 131. Palindrome Partitioning [M]
// LeetCode palindrome-partitioning

class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, bool> memo;
    bool check(string& s) {
        if(memo.contains(s)) return memo[s];
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(s[left] != s[right]) return memo[s] = false;
            left += 1;
            right -= 1;
        }
        return memo[s] = true;
    }
    void dfs(string& s, vector<string>& cur, int pos) {
        if(pos == s.size()) {
            ans.push_back(cur);
            return;
        }
        string temp = "";
        for(int i = pos; i < s.size(); i ++) {
            temp += s[i];
            if(!check(temp)) continue;
            cur.push_back(temp);
            dfs(s, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        dfs(s, temp, 0);
        return ans;
    }
};