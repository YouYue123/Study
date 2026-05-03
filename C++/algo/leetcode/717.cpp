#include <bits/stdc++.h>
using namespace std;

// 717. 1-bit and 2-bit Characters [E]
// LeetCode 1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(bits[n - 1] == 1) return false;
        int i = 0;
        while(i < n) {
            if(i == n - 1) return true;
            if(bits[i] == 1) i += 2;
            else i += 1;
        }
        return false;
    }
};