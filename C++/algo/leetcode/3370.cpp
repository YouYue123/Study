// 3370. Smallest Number With All Set Bits [E]
// LeetCode smallest-number-with-all-set-bits

class Solution {
public:
    int smallestNumber(int n) {
        bool isAllOne = true;
        int ans = 1;
        int ori = n;
        while(n) {
            if(n % 2  == 0) {
                isAllOne = false;
            }
            n /= 2;
            ans *= 2;
        }
        if(isAllOne) return ori;
        else return ans - 1;
    }
};