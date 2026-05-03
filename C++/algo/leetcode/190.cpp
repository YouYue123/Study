// 190. Reverse Bits [E]
// LeetCode reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        int power = 31;
        while(n != 0) {
            ans += (n & 1) << power;
            power -= 1;
            n /= 2;
        }
        return ans;
    }
};