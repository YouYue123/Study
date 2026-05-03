// 1751. Maximum Number of Events That Can Be Attended II [H]
// LeetCode maximum-number-of-events-that-can-be-attended-ii

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector memo(n, vector(k, -1));
        auto dfs = [&] (this auto&& dfs, int i, int cnt) {
            if(i == n || cnt == k) return 0;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            int ans = dfs(i + 1, cnt);
            int left = i, right = n, idx = -1;
            while(left + 1 < right) {
                int mid = left + (right - left) / 2;
                if(events[mid][0] > events[i][1]) {
                    right = mid;
                    idx = mid;
                } else {
                    left = mid;
                }
            }
            if(idx != -1) ans = max(ans, dfs(idx, cnt + 1) + events[i][2]);
            ans = max(ans, events[i][2]);
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0);
    }
};