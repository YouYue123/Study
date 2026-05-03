// 3067. Count Pairs of Connectable Servers in a Weighted Tree Network [M]
// LeetCode count-pairs-of-connectable-servers-in-a-weighted-tree-network

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    int signalSpeed;
    int dfs(int cur, int pre, int curSum) {
        int cnt = curSum % signalSpeed == 0;
        for(auto& [next, w] : graph[cur]) {
            if(next != pre) cnt += dfs(next, cur, curSum + w);
        }
        return cnt;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        this->signalSpeed = signalSpeed;
        for(auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            graph[x].push_back({ y, w });
            graph[y].push_back({ x, w });
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i ++) {
            int sum = 0;
            // cout << i << "=====" << endl;
            for(auto& p : graph[i]) {
                int cnt = dfs(p.first, i, p.second);
                // cout << cnt << endl;
                ans[i] += cnt * sum;
                sum += cnt;
            }

        }
        return ans;
    }
};