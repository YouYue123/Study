#include <bits/stdc++.h>
using namespace std;

// 796. Rotate String [E]
// LeetCode rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string doubleS = s + s;
        return doubleS.contains(goal);
    }
};