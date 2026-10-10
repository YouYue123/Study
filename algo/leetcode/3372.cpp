#include <bits/stdc++.h>
using namespace std;

// 3372. Maximize the Number of Target Nodes After Connecting Trees I [M]
// LeetCode maximize-the-number-of-target-nodes-after-connecting-trees-i


class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        unordered_map<int, vector<int>> graph1, graph2;
        for (auto& e : edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        vector<vector<int>> dist1(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            queue<int> q;
            q.push(i);
            dist1[i][i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph1[u]) {
                    if (dist1[i][v] == -1) {
                        dist1[i][v] = dist1[i][u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        vector<vector<int>> dist2(m, vector<int>(m, -1));
        for (int i = 0; i < m; ++i) {
            queue<int> q;
            q.push(i);
            dist2[i][i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph2[u]) {
                    if (dist2[i][v] == -1) {
                        dist2[i][v] = dist2[i][u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        int maxScore = 0;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (dist2[i][j] <= k - 1) {
                    cnt++;
                }
            }
            maxScore = max(maxScore, cnt);
        }

        // Compute answer for graph1
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (dist1[i][j] <= k) {
                    cnt++;
                }
            }
            ans.push_back(cnt + maxScore);
        }

        return ans;
    }
};
