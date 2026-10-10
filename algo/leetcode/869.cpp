#include <bits/stdc++.h>
using namespace std;

// 869. Reordered Power of 2 [M]
// LeetCode reordered-power-of-2

class Solution {
public:
    bool reorderedPowerOf2(int n) {
       auto order = [&] (int x) -> string {
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
       };
       string target = order(n);
       for(int i = 0; i <= 31; i ++) {
            if(order(1 << i) == target) return true;
       }
       return false;
    }
};