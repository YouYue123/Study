// 2054. Two Best Non-Overlapping Events [M]
// LeetCode two-best-non-overlapping-events

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector memo(n, vector(2, -1));
        auto dfs = [&] (this auto&& dfs, int i, int cnt) {
            if(i == n || cnt == 2) return 0;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            int ans = dfs(i + 1, cnt);
            int left = i + 1, right = n - 1, idx = -1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(events[mid][0] > events[i][1]) {
                    right = mid - 1;
                    idx = mid;
                }  else {
                    left = mid + 1;
                }
            } 
            if(idx != -1) ans = max(ans, dfs(idx, cnt + 1) + events[i][2]);
            ans = max(ans, events[i][2]);
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0);
     }
};