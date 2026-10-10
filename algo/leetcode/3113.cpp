#include <bits/stdc++.h>
using namespace std;

// 3113. Find the Number of Subarrays Where Boundary Elements Are Maximum [H]
// LeetCode find-the-number-of-subarrays-where-boundary-elements-are-maximum

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = 0;
        stack<pair<int, int>> s;
        for(int i = 0; i < nums.size(); ++i) {
            while(!s.empty() && s.top().first < nums[i]) s.pop();
            if(s.empty() || s.top().first > nums[i]) s.push({nums[i], 0});
            s.top().second += 1;
            ans += s.top().second;
        }
        return ans;
    }
};