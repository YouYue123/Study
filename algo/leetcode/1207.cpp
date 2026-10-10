#include <bits/stdc++.h>
using namespace std;

// 1207. Unique Number of Occurrences [E]
// LeetCode unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> dict;
        unordered_map<int, bool> count;
        for(int num : arr) dict[num] += 1;
        for(auto pair: dict) {
            if(count[pair.second]) return false;
            count[pair.second] = true;
        }
        return true;
    }
};