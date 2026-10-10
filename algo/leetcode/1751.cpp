#include <bits/stdc++.h>
using namespace std;

// 1751. Maximum Number of Events That Can Be Attended II [H]
// LeetCode maximum-number-of-events-that-can-be-attended-ii

class Solution {
    public:
        int maxValue(vector<vector<int>>& events, int k) {
            int n = events.size();
            sort(events.begin(), events.end(), [&] (auto& a, auto& b) {
                return a[0] < b[0];
            });
            vector memo(n, vector(k, -1));
            auto dfs = [&] (this auto&& dfs, int i, int cnt) {
                if(i >= n || cnt == k) return 0;
                if(memo[i][cnt] != -1) return memo[i][cnt];
                auto& e = events[i];
                auto it = upper_bound(events.begin(), events.end(), e[1],[&] (int end_day, auto& a) {
                    return end_day < a[0];
                });
                return memo[i][cnt] = max(
                    dfs(i + 1, cnt),
                    dfs(it - events.begin(), cnt + 1) + e[2]
                );
            };
            return dfs(0, 0);
        }
};