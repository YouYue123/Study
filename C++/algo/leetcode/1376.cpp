// 1376. Time Needed to Inform All Employees [M]
// LeetCode time-needed-to-inform-all-employees

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < manager.size(); i ++) {
            int m = manager[i];
            graph[m].push_back(i);
        }
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({ headID, 0 });
        while(!q.empty()) {
            int n = 0;
            auto cur = q.front();
            q.pop();
            auto nextList = graph[cur.first];
            int nextTime = informTime[cur.first] + cur.second;
            ans = max(ans, nextTime);
            for(int nextId : nextList) {
                q.push({ nextId, nextTime });
            }
        }
        return ans;
    }
};