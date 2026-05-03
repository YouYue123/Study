// 310. Minimum Height Trees [M]
// LeetCode minimum-height-trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return { 0 };
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> g;
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
            indegree[u] += 1;
            indegree[v] += 1;
        }
        queue<int> q;
        for(int i = 0; i < n; i ++) {
            if(indegree[i] == 1) q.push(i);
        }
        int remainingNodes = n;
        while(remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;
            for(int i = 0; i < size; i ++) {
                int cur = q.front();
                q.pop();
                for(int nxt : g[cur]) {
                    indegree[nxt] -= 1;
                    if(indegree[nxt] == 1) q.push(nxt);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};