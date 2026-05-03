// 752. Open the Lock [M]
// LeetCode open-the-lock

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        // if(dead.contains("0000")) return -1;
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.emplace("0000", 0);
        visited.insert("0000");
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(dead.contains(cur.first)) continue;
            if(cur.first == target) return cur.second;
            for(int i = 0; i < 4; i ++) {
                for(int diff : {-1, 1}) {
                    string nxt = cur.first;
                    nxt[i] = ((nxt[i] - '0' + diff + 10) % 10) + '0';
                    if(visited.contains(nxt)) continue;
                    visited.insert(nxt);
                    q.emplace(nxt, cur.second + 1);
                }
            }
        }
        return -1;
    }
};