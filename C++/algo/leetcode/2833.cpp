#include <bits/stdc++.h>
using namespace std;

// 2833. Furthest Point From Origin [E]
// LeetCode furthest-point-from-origin

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int left_cnt = 0, right_cnt = 0;
        for(char m : moves) {
            if(m == 'L') left_cnt += 1;
            else if(m == 'R') right_cnt += 1;
        }
        return abs(left_cnt - right_cnt) + n - (left_cnt + right_cnt);
    }
};