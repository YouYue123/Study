// 509. Fibonacci Number [E]
// LeetCode fibonacci-number

class Solution {
public:
    unordered_map<int, int> memo;
    int fib(int n) {
        if(memo.contains(n)) return memo[n];
        if(n == 0) return 0;
        if(n == 1) return 1;
        return memo[n] = fib(n - 1) + fib(n - 2);
    }
};