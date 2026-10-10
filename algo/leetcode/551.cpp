#include <bits/stdc++.h>
using namespace std;

// 551. Student Attendance Record I [E]
// LeetCode student-attendance-record-i

class Solution {
public:
    bool checkRecord(string s) {
        int aCount = 0;
        int lCount = 0;
        bool aValid = true;
        bool lInvalid = false;
        for(char c : s) {
            if(c == 'L') {
                lCount += 1;
            } else if (c == 'A'){
                aCount += 1;
                lCount = 0;
            } else {
                lCount = 0;
            }
            // cout << aCount << " " << lCount << endl;
            if(lCount >= 3) return false;
            if(aCount >= 2) return false;
        }
        return true;
    }
};