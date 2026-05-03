#include <bits/stdc++.h>
using namespace std;

// 2024. Maximize the Confusion of an Exam [M]
// LeetCode maximize-the-confusion-of-an-exam

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int tCnt = 0, fCnt = 0;
        int left = 0, right = 0;
        int historicalMaxFreq = 0;
        while(right < n) {
            if(answerKey[right] == 'T') {
                tCnt += 1;
            } else {
                fCnt += 1;
            }
            historicalMaxFreq = max({
                historicalMaxFreq,
                tCnt,
                fCnt
            });
            if(right - left + 1 > historicalMaxFreq + k) {
                if(answerKey[left] == 'T') {
                    tCnt -= 1;
                } else {
                    fCnt -= 1;
                }
                left += 1;
            }
            right += 1;
        }
        return right - left;
    }
};