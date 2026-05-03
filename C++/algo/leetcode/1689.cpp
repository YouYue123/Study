#include <bits/stdc++.h>
using namespace std;

// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers [M]
// LeetCode partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char c : n) {
            ans = max(ans, c - '0');
        }
        return ans;
    }
};