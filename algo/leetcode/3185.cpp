#include <bits/stdc++.h>
using namespace std;

// 3185. Count Pairs That Form a Complete Day II [M]
// LeetCode count-pairs-that-form-a-complete-day-ii

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> dict;
        long long ans = 0;
        for(int h : hours) {
            int comple = (24 - h % 24) % 24;
            ans += dict[comple];
            dict[h % 24] += 1;
        }
        return ans;
    }
};