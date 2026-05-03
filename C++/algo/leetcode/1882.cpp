// 1882. Process Tasks Using Servers [M]
// LeetCode process-tasks-using-servers

struct Server {
    int idx;
    int weight;
    int endTime;
    bool operator > (const Server& other) const {
        if(weight == other.weight) {
            return idx > other.idx;
        }
        return weight > other.weight;
    }
};
struct Compare {
    bool operator() (const Server& a, const Server& b) const {
        if(a.endTime == b.endTime) {
            if(a.weight == b.weight) {
                return a.idx > b.idx;
            }
            return a.weight > b.weight;
        }
        return a.endTime > b.endTime;
    }
};
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<Server, vector<Server>, greater<>> pq;
        priority_queue<Server, vector<Server>, Compare> workingPq;
        for(int i = 0; i < servers.size(); i ++) pq.emplace(i, servers[i], 0);
        vector<int> ans;
        for(int j = 0; j < tasks.size(); j += 1) {
            // cout << "curTime: " << j << " WorkingPq size: " << workingPq.size() << endl;
            while(!workingPq.empty() && workingPq.top().endTime <= j) {
                // cout << "release " << workingPq.top().idx << endl;
                // cout << "working server endTime: " << workingPq.top().endTime << endl;
                pq.push(workingPq.top());
                workingPq.pop();
            }
            if(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                workingPq.emplace(cur.idx, cur.weight, j + tasks[j]);
                ans.push_back(cur.idx);
            } else {
                auto cur = workingPq.top();
                workingPq.pop();
                workingPq.emplace(cur.idx, cur.weight, cur.endTime + tasks[j]);
                ans.push_back(cur.idx);
            }
        }
        return ans;
    }
};