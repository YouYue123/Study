// 1317. Convert Integer to the Sum of Two No-Zero Integers [E]
// LeetCode convert-integer-to-the-sum-of-two-no-zero-integers

class Solution {
    unordered_map<int, bool> memo;
    bool hasZero(int n) {
        if (memo.contains(n)) {
            return memo[n];
        }
        bool ans = false;
        if (n == 0) {
            ans = true; 
        } else if (n < 10) {
            ans = false;
        } else {
            ans = n % 10 == 0 || hasZero(n / 10);
        }
        memo[n] = ans;
        return memo[n];
     }
public:
    vector<int> getNoZeroIntegers(int n) {
        int cur = 1;
        for (int i = 1; i < n; i ++) {
            if (!hasZero(i) && !hasZero(n - i)) {
                return {i , n - i};
            }
        }
        return {-1, -1};
    }
};