// 3281. Maximize Score of Numbers in Ranges [M]
// LeetCode maximize-score-of-numbers-in-ranges

class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        auto isValid = [&] (long score) {
           long long x = LLONG_MIN;
           for(int s : start) {
                x = max(x + score, (long long) s);
                if(x > s + d) return false;
           }
           return true;
        };
        sort(start.begin(), start.end());
        long long left = 1, right = 1e12;
        while(left < right) {
            long mid = left + (right - left) / 2;
            if(isValid(mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};