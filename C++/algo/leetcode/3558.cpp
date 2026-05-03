// 3558. Number of Ways to Assign Edge Weights I [M]
// LeetCode number-of-ways-to-assign-edge-weights-i

constexpr int MOD = 1e9 + 7;

int modMult(int a, int b, int mod = MOD) {
    return ((long long)(a) * b) % mod;
}

int modPow(int base, int exp, int mod = MOD) {
    long long result = 1;
    while (exp) {
        if (exp & 1) {
            result = modMult(result, base);
        }
        exp /= 2;
        base = modMult(base, base);
    }

    return result;
}


class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int maxDepth = 0;
        unordered_map<int, vector<int>> graph;
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        queue<pair<int, int>> q;
        q.push({1, 0});
        unordered_map<int, bool> visited;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(visited[cur.first]) continue;
            visited[cur.first] = true;
            maxDepth = max(maxDepth, cur.second);
            for(auto next : graph[cur.first]) {
                q.push({next, cur.second + 1});
            }
        }
        // cout << maxDepth << endl;
        return modPow(2, maxDepth - 1);
    }
};