// 3154. Find Number of Ways to Reach the K-th Stair [H]
// LeetCode find-number-of-ways-to-reach-the-k-th-stair

class Solution {
public:
    int waysToReachStair(int k) {
        unordered_map<long long, int> memo;
        auto dfs = [&] (this auto&& dfs, int i, bool prevDown, int jump) {
            if(i > k + 1) return 0;
            long long state = ((long long)i << 32) | (jump << 1) | prevDown; 
            if(memo.contains(state)) return memo[state];
            int ans = 0;
            if(i == k) ans += 1;
            if(prevDown == false) ans += dfs(i - 1, true, jump);
            ans += dfs(i + (1 << jump), false, jump + 1);
            return memo[state] = ans;
        };
        
        return dfs(1, false, 0);
    }
};