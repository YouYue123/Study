// 2402. Meeting Rooms III [H]
// LeetCode meeting-rooms-iii

struct Room {
    long long end;
    int idx;
    bool operator>(const Room& other) const {
        if (end == other.end) return idx > other.idx;
        return end > other.end;
    };
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> free;
        priority_queue<Room, vector<Room>, greater<>> use;
        int ans = -1;
        int maxFreq = INT_MIN;
        vector<int> cntFreq(n, 0);
        for(int i = 0; i < n; i ++) free.push(i); 
        for(auto& m : meetings) {
            int s = m[0], e = m[1];
            while(!use.empty() && use.top().end <= s) {
                free.push(use.top().idx);
                use.pop();
            }
            int assigned = 0;
            if(!free.empty()) {
                assigned = free.top();
                use.emplace(e, assigned);
                free.pop();
            } else {
                auto cur = use.top();
                assigned = cur.idx;
                use.pop();
                use.emplace(cur.end + (e - s), assigned);
            }
            cntFreq[assigned] += 1;
        }       
        for(int i = 0; i < n; i ++) {
            if(cntFreq[i] > maxFreq) {
                maxFreq = cntFreq[i];
                ans = i;
            }
        } 
        return ans;
    }
};