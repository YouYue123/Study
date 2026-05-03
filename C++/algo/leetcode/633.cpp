// 633. Sum of Square Numbers [M]
// LeetCode sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c);
        while(a <= b) {
            long long sum = 1LL * a * a + b * b;
            if(sum == c) return true;
            else if(sum < c) {
                a ++;
            } else {
                b --;
            }
        }
        return false;
    }
};