// 1353. Maximum Number of Events That Can Be Attended [M]
// LeetCode maximum-number-of-events-that-can-be-attended

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> pq;
        int i = 0, day = 1;
        int ans = 0;
        while(i < n || !pq.empty()) {
            if(pq.empty()) day = events[i][0];
            // cout << i << " " << day << " " << pq.size() << endl;
            while(i < n && day >= events[i][0]) {
                pq.push(events[i][1]);
                i += 1;
            }
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            if(!pq.empty()) {
                pq.pop();
                day += 1;
                ans += 1;
            }
        }
        return ans;
    }
};