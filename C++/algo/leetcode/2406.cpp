#include <bits/stdc++.h>
using namespace std;

// 2406. Divide Intervals Into Minimum Number of Groups [M]
// LeetCode divide-intervals-into-minimum-number-of-groups

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<long long> diff(1e6 + 2);
        for(auto& interval : intervals) {
            diff[interval[0]] += 1;
            diff[interval[1] + 1] -= 1;
        }
        int ans = 0;
        int sum = 0;
        for(int num : diff) {
            sum += num;
            ans = max(ans, sum);
        }
        return ans;
    }
};