// 651. 4 Keys Keyboard [M]
// LeetCode 4-keys-keyboard

class Solution {
public:
    int maxA(int n) {
        vector memo(n + 1, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == 0) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = dfs(i - 1) + 1;
            for(int j = 0; j <= i - 2; j ++) {
                ans = max(
                    ans,
                    dfs(j) * (i - j - 1)
                );
            }
            return memo[i] = ans;
        };
        return dfs(n);
    }
};