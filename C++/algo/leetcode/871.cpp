// 871. Minimum Number of Refueling Stops [H]
// LeetCode minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        priority_queue<int> pq;
        int cur_pos = 0, cur_fuel = startFuel;
        int ans = 0;
        for(auto& s : stations) {
            // cout << s.size() << endl;
            int p = s[0], fuel = s[1];
            while(!pq.empty() && cur_pos + cur_fuel < p) {
                cur_fuel += pq.top();
                pq.pop();
                ans += 1;
            }
            cur_fuel -= (p - cur_pos);
            cur_pos = p;
            if(cur_fuel < 0) return -1;
            pq.push(fuel);
        }
        return ans;
    }
};