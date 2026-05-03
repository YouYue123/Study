// 1834. Single-Threaded CPU [M]
// LeetCode single-threaded-cpu

struct Task {
    int idx;
    int enqueueTime;
    int processTime;
    bool operator > (const Task& other) const {
        if(processTime == other.processTime) return idx > other.idx;
        return processTime > other.processTime;
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<Task> ts;
        for(int i = 0; i < n; i ++) {
            ts.emplace_back(i, tasks[i][0], tasks[i][1]);
        }
        sort(ts.begin(), ts.end(), [&] (auto& a, auto& b) {
            return a.enqueueTime < b.enqueueTime;
        });
        // for(auto t : ts) cout << t.idx << " " << t.enqueueTime << " " << t.processTime << endl;
        priority_queue<Task, vector<Task>, greater<>> pq;
        long long time = 1, i = 0;
        vector<int> ans;
        while(i < n || !pq.empty()) {
            // cout << i << endl;
            if(pq.empty()) time = max(time, 1LL * ts[i].enqueueTime);
            // cout << "start :" << time << endl;
            while(i < n && time >= ts[i].enqueueTime) {
                pq.push(ts[i]);
                i ++;
            }
            // cout << pq.size() << endl;
            if(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                ans.push_back(cur.idx);
                time += cur.processTime;
            }
            // cout << "end: " << time << endl;
        }
        return ans;
    }
};