#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
            int n = rowConditions.size(), m = colConditions.size();
            vector r_g(k + 1, vector<int>()), c_g(k + 1, vector<int>());
            vector r_degree(k + 1, 0), c_degree(k + 1, 0);
            vector r_map(k + 1, -1), c_map(k + 1, -1);
            auto preprocess = [&] (vector<vector<int>>& conditions, vector<vector<int>>& g, vector<int>& degree) {
                for(auto& condition : conditions) {
                    int u = condition[0], v = condition[1];
                    g[u].push_back(v);
                    degree[v] += 1;
                }
            };
            preprocess(rowConditions, r_g, r_degree);
            preprocess(colConditions, c_g, c_degree);
            auto topo_sort = [&] (vector<vector<int>>& g, vector<int>& degree, vector<int>& ans_map) -> vector<int> {
                queue<int> q;
                vector<int> order;
                int cnt = 0;
                for(int num = 1; num <= k; num ++) {
                    if(degree[num] == 0) {
                        q.emplace(num);
                    }
                }
                while(!q.empty()) {
                    auto cur_idx = q.front();
                    q.pop();
                    if(cur_idx > k) return {};
                    order.push_back(cur_idx);
                    for(auto& nxt_idx : g[cur_idx]) {
                        degree[nxt_idx] -= 1;
                        if(degree[nxt_idx] == 0) {
                            q.emplace(nxt_idx);
                        }
                    }
                }
                if(order.size() < k) return {};
                return order;
            };
            auto r_order = topo_sort(r_g, r_degree, r_map);
            auto c_order = topo_sort(c_g, c_degree, c_map);
            if(r_order.empty() || c_order.empty()) return {};
            for(int i = 0; i < k; i ++) {
                r_map[r_order[i]] = i;
                c_map[c_order[i]] = i;
            }
            vector ans(k, vector(k, 0));
            for(int num = 1; num <= k; num ++) {
                int r_idx = r_map[num], c_idx = c_map[num];
                if(r_idx == -1 || c_idx == -1) return {};
                // cout << "for num: " << num << " " << r_idx << " " << c_idx << endl;
                ans[r_idx][c_idx] = num;
            }
            return ans;
        }
    };