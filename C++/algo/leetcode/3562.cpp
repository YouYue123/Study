// 3562. Maximum Profit from Trading Stocks with Discounts [H]
// LeetCode maximum-profit-from-trading-stocks-with-discounts

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> present, future;
    int B;

    vector<vector<int>> dp0, dp1;

    void dfs(int u) {
        vector<int> merged0(B + 1, 0), merged1(B + 1, 0);
        for (int v : graph[u]) {
            dfs(v);
            vector<int> nxt0(B + 1, 0), nxt1(B + 1, 0);
            for (int b = 0; b <= B; ++b) {
                for (int spend = 0; spend <= b; ++spend) {
                    nxt0[b] = max(nxt0[b], merged0[b - spend] + dp0[v][spend]);
                    nxt1[b] = max(nxt1[b], merged1[b - spend] + dp1[v][spend]);
                }
            }
            merged0.swap(nxt0);
            merged1.swap(nxt1);
        }

        int cost0 = present[u];
        int profit0 = future[u] - cost0;
        int cost1 = present[u] / 2;
        int profit1 = future[u] - cost1;

        dp0[u].assign(B + 1, 0);
        dp1[u].assign(B + 1, 0);

        for (int b = 0; b <= B; ++b) {
            int best0 = merged0[b];
            if (b >= cost0)
                best0 = max(best0, profit0 + merged1[b - cost0]);
            dp0[u][b] = best0;
            int best1 = merged0[b]; 
            if (b >= cost1)
                best1 = max(best1, profit1 + merged1[b - cost1]);
            dp1[u][b] = best1;
        }
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        this->present = present;
        this->future = future;
        B = budget;
        graph.assign(n, {});
        for (auto& e : hierarchy)
            graph[e[0] - 1].push_back(e[1] - 1);
        dp0.assign(n, vector<int>());
        dp1.assign(n, vector<int>());
        dfs(0);
        return dp0[0][B];
    }
};
