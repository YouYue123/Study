#include <bits/stdc++.h>
using namespace std;

// 581. Shortest Unsorted Continuous Subarray [M]
// LeetCode shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int p1 = INT_MAX, p2 = INT_MIN;
        stack<int> incS;
        for(int i = 0; i < n; ++i) {
            while(!incS.empty() && nums[incS.top()] > nums[i]) {
                p1 = min(p1, incS.top());
                incS.pop();
            }
            incS.push(i);
        }
        stack<int> decS;
        for(int i = n - 1; i >= 0; --i) {
            while(!decS.empty() && nums[decS.top()] < nums[i]) {
                p2 = max(p2, decS.top());
                decS.pop();
            }
            decS.push(i);
        }
        if(p1 == INT_MAX || p2 == INT_MIN) return 0;
        return p2 - p1 + 1;
    }
};