// 1109. Corporate Flight Bookings [M]
// LeetCode corporate-flight-bookings

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 2, 0);
        for(auto& booking : bookings) {
            int s = booking[0], e = booking[1], seat = booking[2];
            diff[s] += seat;
            diff[e + 1] -= seat;
        }
        vector<int> ans(n, 0);
        ans[0] = diff[1];
        for(int i = 1; i < n; i ++) {
            ans[i] = ans[i - 1] + diff[i + 1];
        }
        return ans;
    }
};