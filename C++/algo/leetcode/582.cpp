// 582. Kill Process [M]
// LeetCode kill-process

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < pid.size(); i ++) {
            int cur = pid[i];
            int parent = ppid[i];
            graph[parent].push_back(cur);
        }
        queue<int> q;
        q.push(kill);
        vector<int> ans;
        while(!q.empty()) {
            int cur = q.front();
            ans.push_back(cur);
            q.pop();
            for(int child: graph[cur]) q.push(child);
        }
        return ans;
    }
};