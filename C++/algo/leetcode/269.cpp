// 269. Alien Dictionary [H]
// LeetCode alien-dictionary

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> indegree;
        unordered_set<int> chars;
        for(auto& w : words) {
            for(char c: w) chars.insert(c - 'a');
        } 
        for(int i = 1; i < n; i ++) {
            bool found = false;
            for(int j = 0; j < min(words[i].size(), words[i - 1].size()); j ++) {
                if(words[i][j] != words[i - 1][j]) {
                    g[words[i - 1][j] - 'a'].push_back(words[i][j] - 'a');
                    indegree[words[i][j] - 'a'] += 1;
                    found = true;
                    break;
                }
            }
            if(!found && words[i].size() < words[i - 1].size()) return "";
        }
        queue<int> q;
        for(int c : chars) {
            if(indegree[c] == 0) q.push(c);
        }
        string ans = "";
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            ans += ('a' + cur);
            for(int nxt : g[cur]) {
                indegree[nxt] -= 1;
                if(indegree[nxt] == 0) q.push(nxt);
            }
        }
        if(ans.size() != chars.size()) return "";
        return ans;
    }
};