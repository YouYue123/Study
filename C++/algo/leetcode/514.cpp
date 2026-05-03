// 514. Freedom Trail [H]
// LeetCode freedom-trail

int constexpr INF = 0x3f3f3f3f3f;
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = key.size(), m = ring.size();
        vector memo(n, vector(m, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == n) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = INF;
            // cout << key[i] << endl;
            for(int k = 0; k < m; k ++) {
                if(key[i] == ring[k]) {
                    // cout << abs(k - j) << endl;
                    // cout << (j + m - k) % m << endl;
                    ans = min(
                        ans,
                        dfs(i + 1, k) + min(abs((k + m - j) % m), abs((j + m - k) % m)) + 1
                    );
                }
            }
            return memo[i][j] = ans;
        };

        return dfs(0, 0);
    }
};