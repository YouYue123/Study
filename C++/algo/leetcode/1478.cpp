// 1478. Allocate Mailboxes [H]
// LeetCode allocate-mailboxes

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        
        vector ms(n, vector(n, 0));
        for(int i = n; i >= 0; i --) {
            for(int j = i + 1; j < n; j ++) {
                ms[i][j] = ms[i + 1][j - 1] + houses[j] - houses[i];
            }
        }

        vector<vector<int>> memo(n, vector<int>(k + 1, -1));
        function<int(int, int)> dfs = [&](int i, int cnt) -> int {
            if (cnt > k) return INT_MAX / 2;  // 避免加法溢出
            if (i == n) return cnt == k ? 0 : INT_MAX / 2;
            if (memo[i][cnt] != -1) return memo[i][cnt];
            
            int ans = INT_MAX / 2;
            for (int j = i; j < n; j++) {
                int remain = dfs(j + 1, cnt + 1);
                ans = min(ans, ms[i][j] + remain);
            }
            return memo[i][cnt] = ans;
        };
        
        return dfs(0, 0);
    }
};