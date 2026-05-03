#include <bits/stdc++.h>
using namespace std;

// 3760. Maximum Substrings With Distinct Start [M]
// LeetCode maximum-substrings-with-distinct-start

class Solution {
public:
    int maxDistinct(string s) {
        set<char> set(s.begin(), s.end());
        return set.size();
    }
};