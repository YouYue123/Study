// 464. Can I Win [M]
// LeetCode can-i-win

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((maxChoosableInteger + 1) * maxChoosableInteger / 2< desiredTotal) return false;
        unordered_map<int, int> memo;
        auto dfs = [&] (this auto&& dfs, int total, int state) -> bool {
            if(memo.contains(state)) return memo[state];
            for(int i = 1; i <= maxChoosableInteger; i ++) {
                if(state & (1 << i)) continue;
                if(total - i <= 0 || !dfs(total - i, state | (1 << i))) {
                    return memo[state] = true;
                }
            }
            return memo[state] = false;
        };

        return dfs(desiredTotal, 0);
    }
};