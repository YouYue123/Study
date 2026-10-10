#include <bits/stdc++.h>
using namespace std;

// 1611. Minimum One Bit Operations to Make Integers Zero [H]
// LeetCode minimum-one-bit-operations-to-make-integers-zero


class Solution {
private:
    std::unordered_map<int, int> memo;
public:
    int minimumOneBitOperations(int n) {
        // 把1变为0需要         1 次操作
        // 把2变为0需要     2 + 1 次操作
        // 把4变为0需要 4 + 2 + 1 次操作
        // ...
        // 一般地，把2^k变为0需要 2^k + 2^(k - 1) + ... + 1 = 2^(k + 1) - 1次操作
        // 以8为例
        // 1000 -> 1001 -> 1011 -> 1010 -> 1110 -> 1111 -> 1101 -> 1100 -> 0100 -> 0101 -> 0111 -> 0110 -> 0010 -> 0011 -> 0001 -> 0000
        //  8   ->  9   ->  11  ->  10  ->  14  ->  15  ->  13  ->  12  ->  4   ->  5   -> 7    -> 6    -> 2    -> 3    -> 1    -> 0
        // f(n) = 1 << bit_with(n) - 1 - f(n - 1 << (bit_with(n) - 1))
        if (n == 0)
            return 0;
        int w = bit_width((unsigned)n);
        // Clear the highest significant bit
        int next = n & ~(1 << (w - 1));
        return (1 << w) - 1 - minimumOneBitOperations(next);
    }
};