#include <bits/stdc++.h>
using namespace std;

// 1055. Shortest Way to Form String [M]
// LeetCode shortest-way-to-form-string

class Solution {
public:
    int shortestWay(string source, string target) {
        int prevP = 0;
        int p = 0;
        int ans = 0;
        while(p < target.size()) {
            for (int i = 0; i < source.size(); i ++) {
                if(source[i] == target[p]) {
                    p += 1;
                }
            }
            if(prevP == p) {
                return -1;
            }
            prevP = p;
            ans += 1;
        }
        return ans;
    }
};