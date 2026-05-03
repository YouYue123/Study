// 3343. Count Number of Balanced Permutations [H]
// LeetCode count-number-of-balanced-permutations

class Solution {
public:
    // Modulus for all arithmetic operations to prevent overflow (10^9 + 7 is a prime).
    long long mod = 1e9 + 7;
    // Vectors to store factorials and their modular inverses for binomial coefficient calculations.
    vector<long long> fact, fact_inv;
    // Input string containing digits.
    string nums;
    // Frequency array to store count of each digit (0 to 9) in the input string.
    vector<int> freq;
    // Prefix sum array to store cumulative frequency of digits up to index i.
    vector<int> freqPrefix;
    // 3D DP array for memoization: [digit][diff + 400][remainingOdd].
    // - digit: current digit (0-9).
    // - diff: difference between odd and even position sums (offset by 400 to handle negatives).
    // - remainingOdd: remaining odd positions to fill.
    long long dp[10][801][81];

    // Precomputes factorials and their modular inverses up to maxN for efficient nCr calculations.
    void precomputeFactorials(int maxN) {
        // Initialize factorial and inverse arrays with 1.
        fact.resize(maxN + 1, 1);
        fact_inv.resize(maxN + 1, 1);
        // Compute factorials: fact[i] = i! % mod.
        for (int i = 2; i <= maxN; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        // Compute inverse of maxN! using modular inverse.
        fact_inv[maxN] = mod_inv(fact[maxN]);
        // Compute remaining inverses: fact_inv[i] = fact_inv[i+1] * (i+1) % mod.
        for (int i = maxN - 1; i > 0; i--) {
            fact_inv[i] = (fact_inv[i + 1] * (i + 1)) % mod;
        }
        // Set fact_inv[0] = 1 (0! = 1, inverse = 1).
        fact_inv[0] = 1;
    }

    // Computes modular multiplicative inverse of x modulo mod using Fermat's Little Theorem.
    // Returns x^(mod-2) % mod, assuming mod is prime.
    long long mod_inv(long long x) {
        long long res = 1, power = mod - 2;
        // Binary exponentiation to compute x^(mod-2).
        while (power) {
            if (power % 2) res = res * x % mod; // If power is odd, multiply result by x.
            x = x * x % mod; // Square x.
            power /= 2; // Divide power by 2.
        }
        return res;
    }

    // Computes binomial coefficient C(n, r) = n! / (r! * (n-r)!) modulo mod.
    long long ncr(long long n, long long r) {
        // Return 0 for invalid cases (r > n or r < 0).
        if (r > n || r < 0) return 0;
        // C(n, r) = fact[n] * fact_inv[r] * fact_inv[n-r] % mod.
        return (fact[n] * fact_inv[r] % mod * fact_inv[n - r] % mod) % mod;
    }

    // Recursive DFS with memoization to compute number of balanced permutations.
    // Parameters:
    // - digit: current digit being processed (0 to 9).
    // - diff: current difference (sum of odd positions - sum of even positions).
    // - remainingOdd: number of remaining odd positions to fill.
    long long dfs(int digit, int diff, int remainingOdd) {
        // Count digits used (sum of frequencies of digits < current digit).
        long long countLessThanDigit = digit > 0 ? freqPrefix[digit - 1] : 0;
        // Compute remaining even positions: total - used - odd.
        long long remainingEven = nums.size() - countLessThanDigit - remainingOdd;
        // Invalid state if remaining odd or even positions are negative.
        if (remainingOdd < 0 || remainingEven < 0) return 0;
        // Base case: all digits processed; return 1 if sums are equal (diff = 0).
        if (digit >= 10) return diff == 0;
        // Check memoized result (offset diff by 400 to handle negative values).
        if (dp[digit][diff + 400][remainingOdd] != -1) 
            return dp[digit][diff + 400][remainingOdd];

        // Initialize answer for current state.
        long long ans = 0;
        // Try placing i occurrences of current digit in odd positions.
        for (int oddOcc = 0; oddOcc <= freq[digit]; oddOcc++) {
            // Remaining occurrences go to even positions.
            int evenOcc = freq[digit] - oddOcc;
            // Update difference: odd adds i*digit, even subtracts (freq[digit]-i)*digit.
            long long new_diff = diff + (oddOcc * digit) - (evenOcc * digit);
            // Compute combinations:
            // - Choose oddOcc odd positions: C(remainingOdd, oddOcc).
            // - Choose evenOcc even positions: C(remainingEven, evenOcc).
            long long combo = (ncr(remainingOdd, oddOcc) * ncr(remainingEven, evenOcc)) % mod;
            // Recurse for next digit, update remaining odd positions, and accumulate result.
            ans = (ans + dfs(digit + 1, new_diff, remainingOdd - oddOcc) * combo % mod) % mod;
        }
        // Store and return result for current state.
        return dp[digit][diff + 400][remainingOdd] = ans;
    }

    // Main function to count balanced permutations of the input string.
    // A balanced permutation has equal sums of digits in odd and even positions.
    int countBalancedPermutations(string nums) {
        // Store input string.
        this->nums = nums;
        // Initialize frequency array for digits 0-9.
        freq.assign(10, 0);
        // Count frequency of each digit in the input string.
        for (char c : nums) freq[c - '0']++;
        
        // Initialize prefix sum array for frequencies.
        freqPrefix.assign(10, 0);
        int sum = 0;
        // Compute prefix sums: freqPrefix[i] = sum of frequencies of digits 0 to i.
        for (int i = 0; i < freqPrefix.size(); i++) {
            sum += freq[i];
            freqPrefix[i] = sum;
        }

        // Initialize DP array with -1 (uncomputed states).
        memset(dp, -1, sizeof(dp));
        // Reassign nums (redundant but harmless).
        this->nums = nums;
        // Calculate number of odd and even positions.
        int total_odd = nums.size() / 2; // Floor division for odd positions.
        int total_even = nums.size() - total_odd; // Remaining are even positions.

        // Precompute factorials and inverses for binomial coefficients.
        precomputeFactorials(nums.size());

        // Start DFS with initial state: digit 0, diff 0, all odd positions available.
        return dfs(0, 0, total_odd);
    }
};