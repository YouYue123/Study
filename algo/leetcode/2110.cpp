#include <bits/stdc++.h>
using namespace std;

// 2110. Number of Smooth Descent Periods of a Stock [M]
// LeetCode number-of-smooth-descent-periods-of-a-stock

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0;
        int left = 0;
        for(int right = 0; right < n; right ++) {
            if(right > 0 && prices[right] != prices[right - 1] - 1) {
                left = right;
            }
            // cout << left << " " << right << endl;
            ans += right - left + 1;
        }
        return ans;
    }
};