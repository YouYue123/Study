#include <bits/stdc++.h>
using namespace std;

// 793. Preimage Size of Factorial Zeroes Function [H]
// LeetCode preimage-size-of-factorial-zeroes-function

class Solution {
public:
    int preimageSizeFZF(int K) {
        return rightBound(K) - leftBound(K) + 1;
    }

    long leftBound(int target) {
        long left = 0, right = LONG_MAX;
        while(left < right) {
            long mid = left + ((right - left) / 2);
            if(trailingZero(mid) >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    long rightBound(int target) {
        long left = 0, right = LONG_MAX;
        while(left < right) {
            long mid = left + ((right - left) / 2);
            if(trailingZero(mid) > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }

    long long trailingZero(long long n) {
        long long ans = 0;
        long long divisor = 5;
        while(n >= divisor) {
            ans += n / divisor;
            divisor *= 5;
        }
        return ans;
    }
};