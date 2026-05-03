// 3543. Maximum Weighted K-Edge Path [M]
// LeetCode maximum-weighted-k-edge-path

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    int k;
    int t;
    unordered_map<long, int> memo;
    int dfs(int curNode, int curLength, int sum) {
        if(sum >= t) return INT_MIN;
        if(curLength == k) return sum;
        int ans = INT_MIN;
        long long key = (long)curNode << 48 | (long)curLength << 32 | sum;
        if(memo.contains(key)) return memo[key];
        for(auto& next : graph[curNode]) {
            ans = max(ans, dfs(next.first, curLength + 1, sum + next.second));
        }
        return memo[key] = ans;
    }
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        this->k = k;
        this->t = t;
        for(auto& e : edges) {
            graph[e[0]].push_back({ e[1], e[2] });
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i ++) {
            ans = max(ans, dfs(i, 0, 0));
        }
        return ans == INT_MIN ? -1 : ans;
    }
    
};