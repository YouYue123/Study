// 3593. Minimum Increments to Equalize Leaf Paths [M]
// LeetCode minimum-increments-to-equalize-leaf-paths

class Solution {
public:
    int ans = 0;
    unordered_map<int, vector<int>> graph;
    vector<int> cost;
    long long dfs(int cur, int parent) {
        vector<long long> children;
        for(int next : graph[cur]) {
            if(next == parent) continue;
            children.push_back(dfs(next, cur));
        }
        long long maxChild = 0;
        if(children.size() > 0) {
            maxChild = *max_element(children.begin(), children.end());
            for(long long child : children) {
                if(child < maxChild) ans += 1;
            }
        }
        return cost[cur] + maxChild;
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        this->cost = cost;
        for(auto& e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        return ans;
    }
};