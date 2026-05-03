// 9. Palindrome Number [E]
// LeetCode palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        long long y = 0;
        int temp = x;
        if (x < 0) return false;
        while(x != 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        // cout << x <<  " " << y << endl;
        return temp == y;
    }
};