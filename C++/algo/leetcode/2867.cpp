// 2867. Count Valid Paths in a Tree [H]
// LeetCode count-valid-paths-in-a-tree

const int MX = 1e5;
bool np[MX + 1]; // 质数=false 非质数=true
int init = []() {
    np[1] = true;
    for (int i = 2; i * i <= MX; i++) {
        if (!np[i]) {
            for (int j = i * i; j <= MX; j += i) {
                np[j] = true;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    vector<int> nodes;
    vector<vector<int>> graph;
    void dfs(int cur, int parent) {
        nodes.push_back(cur);
        for(auto next : graph[cur]) {
            if(next == parent || !np[next]) continue;
            dfs(next, cur);
        }
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        graph.resize(n + 1);
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> size(n + 1, 0);
        long long ans = 0;
        for(int i = 1; i <= n; i ++) {
            if(np[i]) continue;
            int sum = 0;
            for(int j : graph[i]) {
                if(!np[j]) continue;
                if(size[j] == 0) {
                    nodes.clear();
                    dfs(j, -1);
                    for(int k : nodes) {
                        size[k] = nodes.size();
                    }
                }
                ans += (long long) size[j] * sum;
                sum += size[j];
            }
            ans += sum;
        }
        return ans;
    }
};