#include <bits/stdc++.h>
using namespace std;

// 1762. Buildings With an Ocean View [M]
// LeetCode buildings-with-an-ocean-view

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int cur_max = 0;
        vector<int> ans;
        for(int i = n - 1; i >= 0; i --) {
            if(heights[i] > cur_max) {
                ans.push_back(i);
            }
            cur_max = max(cur_max, heights[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};