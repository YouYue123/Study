#include <bits/stdc++.h>
using namespace std;

// 1944. Number of Visible People in a Queue [H]
// LeetCode number-of-visible-people-in-a-queue

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> monoS;
        for(int i = 0; i < n; i ++) {
            while(!monoS.empty() && heights[monoS.top()] <= heights[i]) {
                int cur = monoS.top();
                monoS.pop();
                ans[cur] += 1;
            }
            if(!monoS.empty()) ans[monoS.top()] += 1;
            monoS.push(i);
        }
        return ans;
    }
};