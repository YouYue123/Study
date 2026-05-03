// 2145. Count the Hidden Sequences [M]
// LeetCode count-the-hidden-sequences

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long curMin = 0, curMax = 0;
        long long cur = 0;
        for(int diff: differences) {
            cur += diff;
            curMin = min(curMin, cur);
            curMax = max(curMax, cur);
        }
        return max((upper - lower) - (curMax - curMin) + 1, 0LL);
    }
};