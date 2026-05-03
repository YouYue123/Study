#include <bits/stdc++.h>
using namespace std;

// 2748. Number of Beautiful Pairs [E]
// LeetCode number-of-beautiful-pairs

class Solution {
public:
    int firstDigit (int x) {
        int ans = 0;
        while(x > 0) {
            ans = x % 10;
            x /= 10;
        }
        return ans;
    }
    int countBeautifulPairs(vector<int>& nums) {
        vector<int> dict(10, 0);
        int ans = 0;
        for(int num : nums) {
            int lastDigit = num % 10;
            for(int i = 1; i <= 9; i ++) {
                if(__gcd(i, lastDigit) == 1) {
                    ans += dict[i];
                }
            }
            int f = firstDigit(num);
            dict[f] += 1;
        }
        return ans;
    }
};