#include <bits/stdc++.h>
using namespace std;

// 1550. Three Consecutive Odds [E]
// LeetCode three-consecutive-odds

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(int num : arr) {
            if (num % 2) count += 1;
            else count = 0;
            if(count == 3) return true;
        }
        return false;
    }
};