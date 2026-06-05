#include <bits/stdc++.h>
using namespace std;

// 1235. Maximum Profit in Job Scheduling [H]
// LeetCode maximum-profit-in-job-scheduling

struct Job {
    int start_time;
    int end_time;
    int profit;
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs;
        for(int i = 0; i < n; i ++) {
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end(), [&] (auto& a, auto& b) {
            return a.start_time < b.start_time;
        });

        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            auto it = lower_bound(jobs.begin(), jobs.end(), jobs[i].end_time, [&] (auto& a, int end_time) {
                return a.start_time < end_time;
            });
            return memo[i] = max(
                dfs(i + 1),
                jobs[i].profit + dfs(it - jobs.begin())
            );
        };

        return dfs(0);
    }
};