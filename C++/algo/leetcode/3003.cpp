// 3003. Maximize the Number of Partitions After Operations [H]
// LeetCode maximize-the-number-of-partitions-after-operations

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> memo;

        auto dfs = [&] (this auto&& dfs, int cur, int mask, bool hasChanged) {
            if(cur == s.size()) return 1;
            long long key = (long long) cur << 32 | (long long)mask << 1 | hasChanged;
            if(memo.contains(key)) return memo[key];
            int ans = 0;
            int bit = (1 << (s[cur] - 'a'));
            int newMask = mask | bit;
            if(popcount((uint32_t) newMask) > k) {
                ans = dfs(cur + 1, bit, hasChanged) + 1;
            } else {
                ans = dfs(cur + 1, newMask, hasChanged);
            }
            if(!hasChanged) {
                for(int i = 0; i < 26; i ++) {
                    bit = 1 << i;
                    if(mask & bit == 1) continue;
                    newMask = mask | bit;
                    if(popcount((uint32_t) newMask) > k) {
                        ans = max(ans, dfs(cur + 1, bit, true) + 1);
                    } else {
                        ans = max(ans, dfs(cur + 1, newMask, true));
                    }
                }
            }
            return memo[key] = ans;
        };
        return dfs(0, 0, false);
    }
};