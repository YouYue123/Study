#include <bits/stdc++.h>
using namespace std;

// 1235. Maximum Profit in Job Scheduling [H]
// LeetCode maximum-profit-in-job-scheduling

struct Item {
    int start;
    int end;
    int profit;
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Item> items;
        for(int i = 0; i < n; i ++) {
            items.emplace_back(startTime[i], endTime[i], profit[i]);
        } 
        sort(items.begin(), items.end(), [&] (auto& a, auto& b) {
            return a.start < b.start;
        }); 
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans =  dfs(i + 1);
            int left = i, right = n;
            while(left + 1 < right) {
                int mid = left + (right - left) / 2;
                if(items[mid].start < items[i].end) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            ans = max(
                ans,
                dfs(left + 1) + items[i].profit
            );
            return memo[i]= ans;
        };
        // int ans = 0;
        return dfs(0);
    }
};