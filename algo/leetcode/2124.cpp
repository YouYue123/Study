#include <bits/stdc++.h>
using namespace std;

// 2124. Check if All A's Appears Before All B's [E]
// LeetCode check-if-all-as-appears-before-all-bs

class Solution {
public:
    bool checkString(string s) {
        bool hasB = false;
        for(char c : s) {
            if(c == 'a' && hasB) return false;
            if(c == 'b') hasB = true;
        }
        return true;
    }
};