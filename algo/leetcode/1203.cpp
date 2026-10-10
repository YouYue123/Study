#include <bits/stdc++.h>
using namespace std;

// 1203. Sort Items by Groups Respecting Dependencies [H]
// LeetCode sort-items-by-groups-respecting-dependencies

class Solution {
public:
    vector<int> topSort(vector<int>& deg, vector<vector<int>>& g, vector<int>& items) {
        queue<int> q;
        for(auto& item : items) {
            if(deg[item] == 0) q.push(item);
        }
        vector<int> ans;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(auto& v : g[cur]) {
                deg[v] -= 1;
                if(deg[v] == 0) q.push(v);
            }
        }
        return ans.size() == items.size() ? ans : vector<int>{};    
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupItem(n + m);
        
        vector<vector<int>> groupG(n + m);
        vector<int> groupDegree(n + m, 0);

        vector<vector<int>> itemG(n);
        vector<int> itemDegree(n, 0);

        vector<int> id;
        for(int i = 0; i < n + m; i ++) id.push_back(i);
        
        int leftId = m;
        for(int i = 0; i < n; i ++) {
            if(group[i] == -1) {
                group[i] = leftId;
                leftId += 1;
            } 
            groupItem[group[i]].push_back(i);
        }

        for(int curItem = 0; curItem < n; curItem ++) {
            int curGId = group[curItem];
            for(auto& item : beforeItems[curItem]) {
                int beforeGId = group[item];
                if(beforeGId == curGId) {
                    itemDegree[curItem] += 1;
                    itemG[item].push_back(curItem);
                } else {
                    groupDegree[curGId] += 1;
                    groupG[beforeGId].push_back(curGId);
                }
            }
        }

        auto gTopSort = topSort(groupDegree, groupG, id);
        if(gTopSort.size() == 0) return {};
        vector<int> ans;
        for(auto& curGId : gTopSort) {
            int size = groupItem[curGId].size();
            if(size == 0) continue;
            auto subAns = topSort(itemDegree, itemG, groupItem[curGId]);
            if(subAns.size() == 0) return {};
            for(auto& item : subAns) ans.push_back(item);
        }
        return ans;
    }
};