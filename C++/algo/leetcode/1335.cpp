#include <bits/stdc++.h>
using namespace std;

// 1335. Minimum Difficulty of a Job Schedule [H]
// LeetCode minimum-difficulty-of-a-job-schedule

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector memo(n, vector(d + 1, -1));
        auto dfs = [&] (this auto&& dfs , int i, int cnt) {
            if(cnt > d) return INT_MAX;
            if(i == n) return cnt == d ? 0 : INT_MAX;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            int curDiffi = INT_MIN;
            int ans = INT_MAX;
            for(int j = i; j < n; j ++) {
                curDiffi = max(curDiffi, jobDifficulty[j]);
                int remain = dfs(j + 1, cnt + 1);
                if(remain != INT_MAX) {
                    ans = min(ans, curDiffi + remain);
                }
            }
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0) == INT_MAX ? -1 : dfs(0, 0);
    }
};