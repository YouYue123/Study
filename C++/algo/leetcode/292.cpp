#include <bits/stdc++.h>
using namespace std;

// 292. Nim Game [E]
// LeetCode nim-game

class Solution {
    unordered_map<int, bool> memo;
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};