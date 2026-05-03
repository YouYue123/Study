// 3481. Apply Substitutions [M]
// LeetCode apply-substitutions

class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, string> subDict;
        vector<int> indegree(26, 0);
        for(auto& r : replacements) {
            char key = r[0][0];
            string value = r[1];
            int i = 0;
            while(i < value.size()) {
                if(value[i] != '%') {
                    i += 1;
                    continue;
                }
                char nestedKey = value[i  + 1];
                graph[nestedKey].push_back(key);
                indegree[key - 'A'] += 1;
                i += 3;
            }
            subDict[key] = value;
        }
        queue<char> q;
        for(auto& p : subDict) {
            if(indegree[p.first - 'A'] == 0) q.push(p.first);
        }
        // cout << q.size() << endl;
        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            // cout << cur << endl;
            for(char next : graph[cur]) {
                string reg = "%"; 
                reg += cur;
                reg += "%";
                subDict[next] = regex_replace(subDict[next], regex(reg), subDict[cur]);
                indegree[next - 'A'] -= 1;
                if(indegree[next - 'A'] == 0) q.push(next);
            }
        }
        for(auto& p : subDict) {
            string reg = "%"; 
            reg += p.first;
            reg += "%";
            text = regex_replace(text, regex(reg), p.second);
        }
        return text;
    }
};