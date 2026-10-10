#include <bits/stdc++.h>
using namespace std;

// 3622. Check Divisibility by Digit Sum and Product [E]
// LeetCode check-divisibility-by-digit-sum-and-product

class Solution {
public:
    bool checkDivisibility(int n) {
        int cur = n;
        long long digitSum = 0;
        long long digitProd = 1;
        while(cur) {
            digitSum += cur % 10;
            digitProd *= cur % 10;
            cur /= 10;
        }
        long long sum = digitSum + digitProd;
        // cout << sum ;
        return (n % sum) == 0;
    }
};