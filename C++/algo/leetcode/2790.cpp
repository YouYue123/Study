// 2790. Maximum Number of Groups With Increasing Length [H]
// LeetCode maximum-number-of-groups-with-increasing-length

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        long long sum = 0, k = 0;
        for (int a : usageLimits) {
            sum += a;
            if (sum >= (k + 1) * (k + 2) / 2)
                k++;
        }
        return k;
    }
};