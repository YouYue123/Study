#include <bits/stdc++.h>
using namespace std;

// 3468. Find the Number of Copy Arrays [M]
// LeetCode find-the-number-of-copy-arrays

class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        int minStart = INT_MIN;
        int maxStart = INT_MAX;
        int curSum = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                curSum += original[i] - original[i - 1];
            }
            minStart = max(minStart, bounds[i][0] - curSum);
            maxStart = min(maxStart, bounds[i][1] - curSum);
        }
        
        if (minStart > maxStart) {
            return 0;
        }
        
        return maxStart - minStart + 1;
    }
};