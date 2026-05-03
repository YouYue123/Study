// 1318. Minimum Flips to Make a OR b Equal to c [M]
// LeetCode minimum-flips-to-make-a-or-b-equal-to-c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(c != 0) {
            if(c % 2 == 0) {
                if(a % 2 == 1) ans += 1;
                if(b % 2 == 1) ans += 1;
            } else {
                if(a % 2 == 0 && b % 2 == 0) ans += 1;
            }
            c = c / 2;
            a = a / 2;
            b = b / 2;
        }
        while(a != 0) {
            if(a % 2 == 1) ans += 1;
            a = a / 2;
        }
        while(b != 0) {
            if(b % 2 == 1) ans += 1;
            b = b / 2;
        }
        return ans;
    }
};