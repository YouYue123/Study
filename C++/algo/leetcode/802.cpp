// 802. Find Eventual Safe States [M]
// LeetCode find-eventual-safe-states

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        // noCycle
        auto dfs = [&](this auto&& dfs, int i) {
            if(color[i] == 1) return false;
            if(color[i] == 2) return true;
            color[i] = 1;
            for(int nxt : graph[i]) {
                if(!dfs(nxt)) return false;
            }
            color[i] = 2;
            return true;
        };
        vector<int> ans;
        for(int i = 0; i < n; i ++) {
            if(dfs(i)) ans.push_back(i);
        }
        return ans;
    }
};