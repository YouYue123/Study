// 1942. The Number of the Smallest Unoccupied Chair [M]
// LeetCode the-number-of-the-smallest-unoccupied-chair

struct Node {
    int idx;
    long long time;
    bool isArrive;
    bool operator > (const Node& other) const {
        if(time == other.time) {
            return isArrive;
        }
        return time > other.time;
    }
};
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<Node, vector<Node>, greater<>> pq;
        for(int i = 0;  i< times.size(); i ++) {
            pq.emplace(i, times[i][0], true);
            pq.emplace(i, times[i][1], false);
        }
        int thres = 0;
        set<int> dict;
        unordered_map<int, int> seatDict;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(cur.isArrive) {
                // cout << "Arrive " << cur.idx << " at time " << cur.time << endl;
                int ans = 0;
                if(dict.empty()) {
                    ans = thres;
                    thres += 1;
                } else {
                    ans = *dict.begin();
                    dict.erase(*dict.begin());
                }
                // cout << "allocated to " << ans << endl;
                if(cur.idx == targetFriend) return ans;
                seatDict[cur.idx] = ans;
            } else {
                // cout << "Leave " << cur.idx << " at time " << cur.time << endl;
                dict.insert(seatDict[cur.idx]);
            }
        }
        return seatDict[targetFriend];
    }
};