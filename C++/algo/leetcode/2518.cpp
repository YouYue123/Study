// 2518. Number of Great Partitions [H]
// LeetCode number-of-great-partitions

int MOD = 1e9 + 7;

/**
 * Computes base raised to power under modulo arithmetic using binary exponentiation
 * @param base Base number  
 * @param exp Exponent
 * @param mod Modulo value (default: MOD)
 * @return (base^exp) % mod
 */
long long modPow(int base, int exp, int mod = MOD) {
    long long result = 1;
    while (exp) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = ((long long)base * base) % mod;
    }
    return result;
}

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        if(accumulate(nums.begin(), nums.end(), 0LL) < k * 2) return 0;
        int n = nums.size();
        vector<vector<long long>> memo(n, vector<long long>(k + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int target) -> long long {
            if (target < 0)  return 0LL;
            if (i >= n) return target > 0 ? 1LL : 0LL;
            if (memo[i][target] != -1) return memo[i][target];
            long long choose = dfs(i + 1, target - nums[i]);
            long long notChoose = dfs(i + 1, target);
            return memo[i][target] = (choose + notChoose) % MOD;
        };
        
        long long badCnt = dfs(0, k);
        long long total = modPow(2, n);
        // 防止负数
        return (total - badCnt * 2 % MOD + MOD) % MOD;
    }
};