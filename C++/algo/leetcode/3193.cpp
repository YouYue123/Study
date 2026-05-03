// 3193. Count the Number of Inversions [H]
// LeetCode count-the-number-of-inversions

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector req(n, -1);
        for(auto& r : requirements) req[r[0]] = r[1];
        if(req[0] > 0) return 0;
        vector memo(n, vector(401, -1));
        auto dfs = [&] (this auto&& dfs, int end, int cnt) {
            if(end == 0) return cnt == 0 ? 1 : 0;
            if(memo[end][cnt] != -1) return memo[end][cnt];
            int ans = 0;
            if(req[end - 1] >= 0) {
                int r = req[end - 1];
                if(r <= cnt && (cnt - end) <= r) {
                    ans = dfs(end - 1, r);
                }
            } else {
                for(int i = 0; i <= min(end, cnt); i ++) {
                    ans = (ans + dfs(end - 1, cnt - i)) % MOD;
                }
            }
            return memo[end][cnt] = ans;
        };

        return dfs(n - 1, req[n - 1]);
    }
};