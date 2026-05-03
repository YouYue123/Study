#include <bits/stdc++.h>
using namespace std;

// 3536. Maximum Product of Two Digits [E]
// LeetCode maximum-product-of-two-digits

class Solution {
public:
    int maxProduct(int n) {
        unordered_map<int, int> dict;
        while(n > 0) {
            dict[n % 10] += 1;
            n /= 10;
        }
        int n1 = -1, n2 = -1;
        for(int i = 9; i >= 0; --i) {
            while(dict[i]) {
                if(n1 == -1) {
                    n1 = i;
                    dict[i] -= 1;
                }
                else if(n2 == -1) {
                    n2 = i;
                    return n1 * n2;
                }
            }
        }
        return 0;
    }
};