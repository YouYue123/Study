// 2894. Divisible and Non-divisible Sums Difference [E]
// LeetCode divisible-and-non-divisible-sums-difference

class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long num1 = 0, num2 = 0;
        for(int i = 1; i <= n; i ++) {
            if(i % m == 0) num2 += i;
            else num1 += i;
        }
        return num1 - num2;
    }
};