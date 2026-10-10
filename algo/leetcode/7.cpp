// 7. Reverse Integer [M]
// LeetCode reverse-integer

class Solution {
public:
    int reverse(long long x) {
        if(x == 0) return 0;
        bool is_neg = x < 0;
        x = abs(x);
        long long ans = 0;
        while(x > 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if(ans > pow(2, 31) - 1 || ans < - pow(2, 32)) return 0;
        return is_neg ? -ans : ans;
    }
};