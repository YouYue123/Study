// 2187. Minimum Time to Complete Trips [M]
// LeetCode minimum-time-to-complete-trips

class Solution {
public:
    bool isValid(long long mid, vector<int>& time, int totalTrips) {
        long long sum = 0;
        for(int t : time) sum +=  mid / t;
        return sum >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = (long long)totalTrips * (*max_element(time.begin(), time.end()));
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(isValid(mid, time, totalTrips)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};