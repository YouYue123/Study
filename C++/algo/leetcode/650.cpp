// 650. 2 Keys Keyboard [M]
// LeetCode 2-keys-keyboard

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        vector memo(n, vector(n, -1));
        auto dfs = [&](this auto&& dfs, int i, int pasteCnt) {
            if(i == n) return 0;
            if(i > n) return INF;
            if( memo[i][pasteCnt]!= -1) return memo[i][pasteCnt];
            int ans = min(
                2 + dfs(i + i, i),
                1 + dfs(i + pasteCnt, pasteCnt)
            );
            return memo[i][pasteCnt] = ans;
        };

        return 1 + dfs(1, 1);
    }
};