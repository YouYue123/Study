// 433. Minimum Genetic Mutation [M]
// LeetCode minimum-genetic-mutation

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> banks;
        for(string& b: bank) banks.insert(b);
        if(!banks.contains(endGene)) return -1;
        // AACCGGTA
        // ["AACCGGTA","AACCGCTA","AAACGGTA"]
        // AAACGGTA
        unordered_map<string, bool> visited;
        queue<pair<string, int>> q;
        q.emplace(startGene, 0);
        vector<char> m = { 'C', 'G', 'T', 'A' };
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            visited[cur.first] = true;
            // cout << cur << endl;
            if(cur.first == endGene) return cur.second;
            for(int i = 0; i < cur.first.size(); i ++) {
                for(char c : m) {
                    if(c == cur.first[i]) continue;
                    int temp = cur.first[i];
                    cur.first[i] = c;
                    if(banks.contains(cur.first) && !visited[cur.first]) q.emplace(cur.first, cur.second + 1);
                    cur.first[i] = temp;
                }
            }
        }
        return -1;
    }
};