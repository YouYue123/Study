// 3082. Find the Sum of the Power of All Subsequences [H]
// LeetCode find-the-sum-of-the-power-of-all-subsequences

int MOD = 1e9 + 7;
/**
 * Computes base raised to power under modulo arithmetic using binary exponentiation
 * @param base Base number
 * @param exp Exponent
 * @param mod Modulo value (default: MOD)
 * @return (base^exp) % mod
 */
long long modPow(int base, int exp, int mod = MOD)
{
    long long result = 1;
    while (exp)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = ((long long)base * base) % mod;
    }

    return result;
}
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        vector memo(
            n,
            vector(
                k,
                vector(n, -1LL)
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int curSum, int len) {
            if(curSum == k) return modPow(2, n - len);
            if(i >= n || curSum > k) return 0LL;
            if(memo[i][curSum][len] != -1) return memo[i][curSum][len];
            return memo[i][curSum][len] = (dfs(i + 1, curSum, len) + dfs(i + 1, curSum + nums[i], len + 1)) % MOD;
        };
        return dfs(0, 0, 0);
    }
};