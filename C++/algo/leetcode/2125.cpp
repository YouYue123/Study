#include <bits/stdc++.h>
using namespace std;

// 2125. Number of Laser Beams in a Bank [M]
// LeetCode number-of-laser-beams-in-a-bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int pre = 0;
        for(string& row : bank) {
            int cnt = 0;
            for(char c : row) { 
                if(c == '1') cnt += 1;
            }
            ans += pre * cnt;
            if(cnt != 0) pre = cnt;
        }
        return ans;
    }
};