// 2737. Find the Closest Marked Node [M]
// LeetCode find-the-closest-marked-node

class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        unordered_map<int, vector<pair<int, int>>> graph;
        unordered_map<int, bool> markedDict;
        unordered_map<int, bool> visited;
        for(vector<int>& e: edges) graph[e[0]].push_back({ e[2], e[1] });
        for(auto item : graph[s])  q.push(item);
        for(int item: marked) markedDict[item] = true;
        int ans = INT_MAX;
        while(!q.empty()) {
            auto cur = q.top();
            q.pop();
            if(visited.contains(cur.second)) continue;
            visited[cur.second] = true;
            // cout << cur.second << endl;
            if(markedDict.contains(cur.second)) {
                ans = min(ans, cur.first);
                continue;
            }
            for(auto next : graph[cur.second]) {
                q.push({
                    next.first + cur.first,
                    next.second,
                });
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};