// 1857. Largest Color Value in a Directed Graph [H]
// LeetCode largest-color-value-in-a-directed-graph

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        if(edges.size() == 0) return 1;
        unordered_map<int, vector<int>> graph;
        int n = colors.size();
        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);
        for(auto& e : edges) {
            int from = e[0], to = e[1];
            indegree[to] += 1;
            outdegree[from] += 1;
            graph[from].push_back(to);
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++) {
            // cout << indegree[i] << endl;
            if(indegree[i] == 0 && outdegree[i] != 0) q.push(i); 
        }
        int ans = -1;
        while(!q.empty()) {
            auto cur = q.front();
            int curC = colors[cur];
            q.pop();
            dp[cur][curC - 'a'] += 1;
            // cout << cur << endl;
            // cout << endl;
            // cout << "curMax " <<  ans << endl;
            for(auto next : graph[cur]) {
                indegree[next] -= 1;
                for(int i = 0; i < 26; i ++) {
                    dp[next][i] = max(dp[next][i], dp[cur][i]);
                }
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
            if(graph[cur].size() == 0) {
                for(int i = 0; i < 26; i ++) {
                    ans = max(ans, dp[cur][i]);
                }
            }
        }
        return ans;
    }
};