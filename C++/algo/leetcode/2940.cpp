#include <bits/stdc++.h>
using namespace std;

// 2940. Find Building Where Alice and Bob Can Meet [H]
// LeetCode find-building-where-alice-and-bob-can-meet

using pii = pair<int, int>;
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector qs(n, vector<pii>());
        vector ans(m, -1);
        for(int i = 0; i < m; i ++) {
            int a = queries[i][0], b = queries[i][1];
            if(a > b) swap(a, b);
            if(a == b || heights[a] < heights[b]) {
                ans[i] = b;
            } else {
                qs[b].emplace_back(heights[a], i);
            }
        }
        priority_queue<pii, vector<pii>, greater<>> pq;
        for(int i = 0; i < n; i ++) {
            int h = heights[i];
            while(!pq.empty() && pq.top().first < h) {
                ans[pq.top().second] = i;
                pq.pop();
            }
            for(auto& nxt : qs[i]) {
                pq.push(nxt);
            }
        }
        return ans;
    }
};