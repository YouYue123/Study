// 935. Knight Dialer [M]
// LeetCode knight-dialer

int MOD = 1e9 + 7;
class Solution {
public:
    int knightDialer(int n) {
        int w = 3, h = 4;
        using pii = pair<int, int>;
        vector<pii> moves =  {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
        vector<vector<int>> dict = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {-1,0, -1}
        };
        vector memo(
            h,
            vector(w, vector(n, -1LL))
        );
        auto dfs = [&] (this auto&& dfs, int i, int j, int cnt) -> long long {
            if(i >= h || i < 0 || j >= w || j < 0) return 0;
            if(dict[i][j] < 0) return 0;
            if(cnt == n) return 1;
            if(memo[i][j][cnt] != -1LL) return memo[i][j][cnt];
            long long ans = 0;
            for(auto m : moves) {
                ans = (ans + dfs(i + m.first, j + m.second, cnt + 1)) % MOD;
            }
            return memo[i][j][cnt] = ans;
        };
        long long ans = 0;
        for(int i = 0; i < h; i ++) {
            for(int j = 0; j < w; j ++) {
                if(dict[i][j] < 0) continue;
                ans = (ans + dfs(i, j, 1)) % MOD;
            }
        }
        return ans;
    }
};