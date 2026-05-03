#include <bits/stdc++.h>
using namespace std;

// 1007. Minimum Domino Rotations For Equal Row [M]
// LeetCode minimum-domino-rotations-for-equal-row

class Solution {
public:
    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int r1 = 0, r2 = 0;
        for(int i = 0; i < tops.size(); i ++) {
            if(tops[i] != x && bottoms[i] != x) return -1;
            else if(tops[i] != x) r1 += 1;
            else if(bottoms[i] != x) r2 += 1;
        }
        return min(r1, r2);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int r = check(tops[0], tops, bottoms);
        if(r != -1 || tops[0] == bottoms[0]) return r;
        else return check(bottoms[0], tops, bottoms);
    }
};