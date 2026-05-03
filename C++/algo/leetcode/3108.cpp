// 3108. Minimum Cost Walk in Weighted Graph [H]
// LeetCode minimum-cost-walk-in-weighted-graph

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    unordered_map<int, bool> visited;
    vector<int> components;
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for(vector<int>& e:edges) {
            this->graph[e[0]].push_back({e[1], e[2]});
            this->graph[e[1]].push_back({e[0], e[2]});
        }
        int componentId = 0;
        components.assign(n, 0);
        vector<int> componentCost;
        for(int node = 0; node < n; node += 1) {
            if(!visited[node]) {
                // cout << node << endl;
                // new component
                int cost = getComponentCost(node, componentId);
                componentCost.push_back(cost);
                componentId += 1;
            }
        }
        // for(int i = 0; i < components.size(); i ++) {
        //     cout << components[i] << endl;
        // }
        vector<int> ans;
        for(vector<int>& q : query) {
            int start = q[0], end = q[1];
            if(components[start] == components[end]) {
                ans.push_back(componentCost[components[start]]);
            } else {    
                ans.push_back(-1);
            }
        }
        return ans;
    }
    // Since the AND operation can only turn bits off (changing 1 to 0, but never 0 to 1)
    // That tells us that adding more edges to a walk can only keep the cost the same or make it smaller. 
    int getComponentCost(int node, int componentId) {
        int cost = INT_MAX;
        components[node] = componentId;
        visited[node] = true;
        for(auto& [neighbor, weight] : graph[node]) {
            cost &= weight;
            if(!visited[neighbor]) {
                cost &= getComponentCost(neighbor, componentId);
            }
        }
        return cost;
    }
};