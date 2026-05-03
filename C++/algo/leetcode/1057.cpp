// 1057. Campus Bikes [M]
// LeetCode campus-bikes

struct Dist {
    int worker;
    int bike;
    int dist;
    Dist(vector<vector<int>>& workers, int i, vector<vector<int>>& bikes, int j) {
        this->worker = i;
        this->bike = j;
        int wX = workers[i][0], wY = workers[i][1];
        int bX = bikes[j][0], bY = bikes[j][1];
        this->dist = abs(wX - bX) + abs(wY - bY);
    }
    
    bool operator<(Dist& other) {
        if(dist == other.dist) {
            if(worker == other.worker) {
                return bike < other.bike;
            } else {
                return worker < other.worker;
            }
        } else {
            return dist < other.dist;
        }
    }

    bool operator>(Dist& other) {
        if(dist == other.dist) {
            if(worker == other.worker) {
                return bike > other.bike;
            } else {
                return worker > other.worker;
            }
        } else {
            return dist > other.dist;
        }
    }
};

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> ans(workers.size(), -1);
        unordered_map<int, bool> hasBikeAssigned;
        priority_queue<Dist, vector<Dist>, greater<>> pq;
        for(int i = 0; i < workers.size(); i ++) {
            for(int j = 0; j < bikes.size(); j ++) {
                pq.push(
                    Dist(workers, i, bikes, j)
                );
            }
        }
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            // cout << cur.dist << endl;
            if(hasBikeAssigned[cur.bike]) continue;
            if(ans[cur.worker] == -1) {
                // cout << "assign bike: " << cur.bike << " to worker: " << cur.worker << endl;
                ans[cur.worker] = cur.bike;
                hasBikeAssigned[cur.bike] = true;
            }
        }
        return ans;
    }
};