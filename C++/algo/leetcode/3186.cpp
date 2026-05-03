// 3186. Maximum Total Damage With Spell Casting [M]
// LeetCode maximum-total-damage-with-spell-casting

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> cnt;
        for(int p : power) cnt[p] += 1;
        sort(power.begin(), power.end());
        vector<long long> memo(power.size() + 1, -1);
        auto dfs = [&] (this auto&& dfs, int i) -> long long {
            if(i >= power.size()) return 0;
            int p = power[i];
            if(memo[i] != -1) return memo[i]; 
            int j = upper_bound(power.begin(), power.end(), p + 2) - power.begin();
            return memo[i] = max(
                dfs(j) + (long long)p * cnt[p],
                dfs(i + 1) 
            );
        };
        return dfs(0);
    }
};