#include <bits/stdc++.h>
using namespace std;

// 1664. Ways to Make a Fair Array [M]
// LeetCode ways-to-make-a-fair-array

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> oddPresum(n + 1, 0);
        vector<int> evenPresum(n + 1, 0);
        for(int i = 0 ;i < n ; i++) {
            if(i % 2 == 0) {
                evenPresum[i + 1] = evenPresum[i] + nums[i];
                oddPresum[i + 1] = oddPresum[i];
            } else {
                oddPresum[i + 1] = oddPresum[i] + nums[i];
                evenPresum[i + 1] = evenPresum[i];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            // cout << evenPresum[i] << " " << oddPresum[i] << endl;
            int evenSum = evenPresum[i] + oddPresum[n] - oddPresum[i + 1];
            int oddSum = oddPresum[i] + evenPresum[n] - evenPresum[i + 1];
            // cout << i << " " << evenSum << " " << oddSum << endl;
            if(evenSum == oddSum) {
                ans += 1;
            }
        }
        return ans;
    }
};