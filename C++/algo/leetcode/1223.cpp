// 1223. Dice Roll Simulation [H]
// LeetCode dice-roll-simulation

int MOD = 1e9 + 7;
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // 1:xxxx 2:xxxx 3:xxxx, ...
        vector memo(n, vector(6, vector(16, -1)));
        auto dfs = [&] (this auto&& dfs, int i, int prevRoll, int rollCnt) {
            if(i == n) return 1;
            if(memo[i][prevRoll][rollCnt] != -1) return memo[i][prevRoll][rollCnt];
            int ans = 0;
            for(int r = 0; r < 6; r ++) {
                if(r == prevRoll && rollCnt == rollMax[r]) continue;
                ans = (ans + dfs(i + 1, r, (r == prevRoll ? rollCnt + 1 : 1))) % MOD;
            }
            return memo[i][prevRoll][rollCnt] = ans;
        };
        return dfs(0, 0, 0);
    }
};