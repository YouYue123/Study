#include <bits/stdc++.h>
using namespace std;

// 1732. Find the Highest Altitude [E]
// LeetCode find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int cur = 0;
        for(int g : gain) {
            cur += g;
            ans = max(ans, cur);
        }
        return ans;
    }
};