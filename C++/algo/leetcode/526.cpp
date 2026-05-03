// 526. Beautiful Arrangement [M]
// LeetCode beautiful-arrangement

class Solution {
public:
    int countArrangement(int n) {
        unordered_map<int, unordered_map<int, int>> memo;
        auto dfs = [&](this auto&& dfs, int i, int state) {
            if(i == n + 1) return 1;
            if(memo.contains(i) && memo[i].contains(state)) return memo[i][state];
            int ans = 0;
            for(int k = 1; k <= n; k ++) {
                int cur = 1 << k;
                if(state & cur) continue;
                if(k % i == 0 || i % k == 0) {
                    ans += dfs(i + 1, state | cur);
                } 
            }
            return memo[i][state] = ans;
        };
        return dfs(1, 0);
    }
};