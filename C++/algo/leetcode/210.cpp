#include <bits/stdc++.h>
using namespace std;

// 210. Course Schedule II [M]
// LeetCode course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g;
        g.assign(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for(auto& p : prerequisites) {
            int a = p[0], b = p[1];
            g[b].push_back(a);
            indegree[a] += 1;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i ++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int nxt : g[cur]) {
                indegree[nxt] -= 1;
                if(indegree[nxt] == 0) q.push(nxt);
            }
        }
        if(ans.size() == numCourses) {
            return ans;
        } else {
            return vector<int>();
        }
    }
};