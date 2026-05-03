#include <bits/stdc++.h>
using namespace std;

// 2337. Move Pieces to Obtain a String [M]
// LeetCode move-pieces-to-obtain-a-string

class Solution {
public:
    bool canChange(const std::string& start, const std::string& target) {
        int n = start.size();
        int i = 0, j = 0;
        
        // Walk through both strings in tandem
        while (i < n && j < n) {
            // skip blanks in start  
            while (i < n && start[i] == '_') ++i;
            // skip blanks in target  
            while (j < n && target[j] == '_') ++j;

            // if either pointer is at end, break to handle leftovers
            if (i == n || j == n) break;

            // chars must match  
            if (start[i] != target[j]) return false;
            // L can't move right, R can't move left  
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;

            ++i;
            ++j;
        }

        // any remaining non-blank in start or target makes it impossible
        while (i < n) {
            if (start[i] != '_') return false;
            ++i;
        }
        while (j < n) {
            if (target[j] != '_') return false;
            ++j;
        }

        return true;
    }
};
