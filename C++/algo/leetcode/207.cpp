// 207. Course Schedule [M]
// LeetCode course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> g;
        for(auto& p : prerequisites) {
            int a = p[0], b = p[1];
            g[b].push_back(a);
            indegree[a] += 1;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i ++) {
            if(indegree[i] == 0) q.push(i);
        }
        int taken_cnt = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            taken_cnt += 1;
            for(auto& nxt : g[cur]) {
                indegree[nxt] -= 1;
                if(indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        return taken_cnt == numCourses;
    }
};