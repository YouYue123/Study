// 1575. Count All Possible Routes [H]
// LeetCode count-all-possible-routes

int MOD = 1e9 + 7;
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector memo(n, vector(fuel + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int f) {
            if(f > fuel) return 0;
            if(memo[i][f] != -1) return memo[i][f];
            int ans = (i == finish ? 1 : 0);
            for(int j = 0; j < n; j ++) {
                if(j == i) continue;
                ans = (ans + dfs(j, f + abs(locations[j] - locations[i]))) % MOD;
            }
            return memo[i][f] = ans;
        };
        return dfs(start, 0);
    }
};