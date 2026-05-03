#include <bits/stdc++.h>
using namespace std;

// 1557. Minimum Number of Vertices to Reach All Nodes [M]
// LeetCode minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> deps;
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            deps.insert(v);
        }
        unordered_set<int> ans;
        for(auto& e : edges) {
            int u = e[0];
            if(!deps.contains(u)) ans.insert(u);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};