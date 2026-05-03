#include <bits/stdc++.h>
using namespace std;

// 3723. Maximize Sum of Squares of Digits [M]
// LeetCode maximize-sum-of-squares-of-digits

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(ans.size() < num) {
            for(int i = 9; i >= 0; i --) {
                if(sum >= i) {
                    sum -= i;
                    ans += (i + '0'); 
                    break;
                }
            }
        }
        return sum == 0 ? ans : "";
    }
};