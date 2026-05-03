#include <bits/stdc++.h>
using namespace std;

// 3547. Maximum Sum of Edge Values in a Graph [H]
// LeetCode maximum-sum-of-edge-values-in-a-graph

class Solution {
public:
    void bfs(const std::vector<std::vector<int>>& adjacencyList, int node, std::vector<bool>& visited, 
             std::vector<int>& cycles, std::vector<int>& non_cycles) {
        int count = 1;
        std::queue<int> q;
        q.push(node);
        visited[node] = true;

        bool flag = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            flag = flag && adjacencyList[x].size() == 2;
            for (int neighbour : adjacencyList[x]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    count++;
                    visited[neighbour] = true;
                }
            }
        }

        if (count <= 1) return;
        
        if (flag) {
            cycles.push_back(count);
        } else {
            non_cycles.push_back(count);
        }
    }
    
    long long maxScore(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        std::vector<bool> visited(n, false);
        std::vector<int> cycles;
        std::vector<int> non_cycles;

        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                bfs(adjacencyList, node, visited, cycles, non_cycles);
            }
        } 

        std::sort(cycles.begin(), cycles.end(), std::greater<int>());
        std::sort(non_cycles.begin(), non_cycles.end(), std::greater<int>());

        int last = n;
        long long ans = 0;

        for (int comp : cycles) {
            std::vector<long long> l(comp);
            int i = 0, j = comp - 1;
            bool turn = true;
            
            while (i <= j) {
                if (turn) {
                    l[i] = last;
                    last--;
                    i++;
                } else {
                    l[j] = last;
                    last--;
                    j--;
                }
                turn = !turn;
            }

            for (int idx = 0; idx < comp; idx++) {
                ans += l[idx] * l[(idx + 1) % comp];
            }
        }

        for (int comp : non_cycles) {
            std::vector<long long> l(comp);
            int i = comp / 2;
            int j = i - 1;

            int tmp1 = last, tmp2 = last - 1;
            while (i < comp) {
                l[i] = tmp1;
                last--;
                tmp1 -= 2;
                i++;
            }

            while (j >= 0) {
                l[j] = tmp2;
                last--;
                tmp2 -= 2;
                j--;
            }

            for (int idx = 0; idx < comp - 1; idx++) {
                ans += l[idx] * l[idx + 1];
            }
        }
        
        return ans;
    }
};