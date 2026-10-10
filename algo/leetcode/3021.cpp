#include <bits/stdc++.h>
using namespace std;

// 3021. Alice and Bob Playing Flower Game [M]
// LeetCode alice-and-bob-playing-flower-game

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long nEvenCnt, nOddCnt = 0;
        long long mEvenCnt, mOddCnt = 0;
        nEvenCnt = n / 2;
        mEvenCnt = m / 2;
        if(n % 2 == 0) {
            nOddCnt = n / 2;
        } else {
            nOddCnt = (n + 1) / 2;
        }
        if (m % 2 == 0) {
            mOddCnt = m / 2;
        } else {
            mOddCnt = (m + 1) / 2;
        }
        return nEvenCnt * mOddCnt + mEvenCnt * nOddCnt;
    }
};