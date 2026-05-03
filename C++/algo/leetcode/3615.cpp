// 3615. Longest Palindromic Path in Graph [H]
// LeetCode longest-palindromic-path-in-graph

class Solution {
public:
    int n;
    string label;
    unordered_map<int, vector<int>> graph;
    unordered_map<long long, unordered_map<int, int>> memo;
    bool isUsed(int mask, int posToCheck) {
        return ((mask >> posToCheck) & 1) == 1;
    }
    int dfs(int u, int v, int mask) {
        if(u > v) swap(u, v);
        long long key = (long long) u << 32 | v;
        if(memo.contains(key) && memo[key].contains(mask)) return memo[key][mask];
        if(u == v) return memo[key][mask] = 1;
        if(label[u] != label[v]) return memo[key][mask] = 0;
        int newMask = mask | (1 << u) | (1 << v);
        int maxInnerLen = 0;
        for(int uNext : graph[u]) {
            if(!isUsed(newMask, uNext)) {
                for(int vNext : graph[v]) {
                    if(!isUsed(newMask, vNext)) {
                        maxInnerLen = max(maxInnerLen, dfs(uNext, vNext, newMask));
                    }
                }
            }
        }
        int ans = 0;
        if(maxInnerLen > 0) {
            ans = 2 + maxInnerLen;
        }
        for(int neighbor : graph[u]) {
            if(neighbor == v && label[u] == label[v]) ans = max(ans, 2);
        }
        return memo[key][mask] = ans;
    }
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        this->n = n;
        this->label = label;
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i ++ ) {
            for(int j = i; j < n; j ++) {
                ans = max(ans, dfs(i, j, 0));
            }
        }
        return ans;
    }
};