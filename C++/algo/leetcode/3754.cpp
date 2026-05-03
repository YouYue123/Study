// 3754. Concatenate Non-Zero Digits and Multiply by Sum I [E]
// LeetCode concatenate-non-zero-digits-and-multiply-by-sum-i

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x =0;
        long long sum = 0;
        // auto n_s = string(n)
        int d = 1;
        while(n) {
            if(n % 10 != 0) {
                x = n % 10 * d + x;
                d *= 10;
            }
            sum += n % 10;
            n /= 10;
        }
        cout << x << " " << sum << endl;
        return x * sum;
    }
};