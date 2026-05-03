// 3341. Find Minimum Time to Reach Last Room I [M]
// LeetCode find-minimum-time-to-reach-last-room-i

struct State {
    int x;
    int y;
    int time;
    State(int _x, int _y, int _time): x(_x), y(_y), time(_time) {}
    bool operator<(const State& other) {
        return time < other.time;
    }
    bool operator>(const State& other) {
        return time > other.time;
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<State, vector<State>, greater<>> pq;
        pq.push(State(0, 0, 0));
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        // Use vector of vectors for better cache locality
        vector<vector<int>> distTo(m, vector<int>(n, INT_MAX));
        distTo[0][0] = 0;
        while(!pq.empty()) {  
            auto [x, y, time] = pq.top();
            pq.pop();
            if (time > distTo[x][y]) continue;
            // cout << "cur: " << cur.x << " " << cur.y << " " << cur.time << endl;
            if(x == m - 1 && y == n - 1) return time;
            for(auto& d : dirs) {
                int nx = x + d.first;
                int ny = y + d.second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;                
                int nTime = max(time , moveTime[nx][ny]) + 1;
                if(nTime >= distTo[nx][ny]) continue;
                distTo[nx][ny] = nTime;
                pq.emplace(nx, ny, nTime);
            }
        }
        return -1;
    }
    // 3 72 14
    // 25 81 5
};