// 1342. Number of Steps to Reduce a Number to Zero [E]
// LeetCode number-of-steps-to-reduce-a-number-to-zero

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) {
            return 0;
        }
        if (num % 2 == 1) {
            return 1 + numberOfSteps(num - 1);
        } else {
            return 1 + numberOfSteps(num / 2);
        }
    }
};