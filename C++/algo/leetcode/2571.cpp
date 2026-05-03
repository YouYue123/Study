// 2571. Minimum Operations to Reduce an Integer to 0 [M]
// LeetCode minimum-operations-to-reduce-an-integer-to-0

class Solution {
private:
    int lowbit(int x) {
        return x & (-x);
    }
public:
    int minOperations(int n) {
    int res = 0;
    while (n > 0) {
        // 如果最后两位是 11 (即 n % 4 == 3)
        if ((n & 3) == 3) {
            n++; // 进位：通过加法把一串 1 变成 0
            res++;
        } else {
            // 如果最后一位是 1 (n % 2 == 1)
            if (n & 1) res++;
            n >>= 1; // 右移处理下一位
        }
    }
    return res;
}
};