#include <bits/stdc++.h>
using namespace std;

// 3442. Maximum Difference Between Even and Odd Frequency I [E]
// LeetCode maximum-difference-between-even-and-odd-frequency-i

class Solution {
public:
    int maxDifference(string s) {
        vector<int> dict(26, 0);
        for(char c : s) dict[c - 'a'] += 1;
        int maxOddFreq = INT_MIN;
        int minEvenFreq = INT_MAX;
        for(int i = 0; i < 26; i ++) {
            if(dict[i] == 0) continue;
            if(dict[i] % 2 != 0) {
                maxOddFreq = max(maxOddFreq, dict[i]);
            } else {
                minEvenFreq = min(minEvenFreq, dict[i]);
            }
        }
        // cout << maxOddFreq << " " << minEvenFreq  << endl;
        return maxOddFreq - minEvenFreq;
    }
};