#include <bits/stdc++.h>
using namespace std;

// 1888. Minimum Number of Flips to Make the Binary String Alternating [M]
// LeetCode minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int ans_1 = 0, ans_2 = 0, ans = 0x3f3f3f3f;
        auto get_desired = [&] (int pos, bool start_with_0) {
            if(start_with_0) {
                return pos % 2 == 0 ? '0' : '1';
            } else {
                return pos % 2 == 0 ? '1' : '0';
            }
        };
        while(right < 2 * n) {
            int right_idx = right % n;
            if(get_desired(right, true) != s[right_idx]) ans_1 += 1;
            if(get_desired(right, false) != s[right_idx]) ans_2 += 1;
            if(right - left + 1 > n) {
                if(get_desired(left, true) != s[left]) ans_1 -= 1;
                if(get_desired(left, false) != s[left]) ans_2 -= 1;
                left += 1;
            }
            if(right - left + 1 == n) {
                ans = min({ ans, ans_1, ans_2 });
            }
            right += 1;
        }
        return ans;
    }
};