// 2579. Count Total Number of Colored Cells [M]
// LeetCode count-total-number-of-colored-cells

class Solution {
public:
    long long coloredCells(int n) {
        // 1 + 4 + 8 + 12 + 16
        // 1 + (1  + .... + n-1) * 4
        long long ans = 1 + 4 *  (long long) (n) * (n-1) / 2;
        return ans;
    }
};