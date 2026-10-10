#include <bits/stdc++.h>
using namespace std;

// 2672. Number of Adjacent Elements With the Same Color [M]
// LeetCode number-of-adjacent-elements-with-the-same-color

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        int contrib = 0;
        vector colors(n, 0);
        for(auto& q : queries) {
            int idx = q[0], color = q[1];
            if(colors[idx] != color) {
                int prevIdx = idx - 1, nxtIdx = idx + 1;
                if(prevIdx >= 0) {
                    if(colors[prevIdx] == color) {
                        contrib += 1;
                    } else if(colors[prevIdx] != 0 && colors[prevIdx] == colors[idx]) {
                        contrib -= 1;
                    }
                }
                if(nxtIdx < n) {
                    if(colors[nxtIdx] == color) {
                        contrib += 1;
                    } else if(colors[nxtIdx] != 0 && colors[nxtIdx] == colors[idx]){
                        contrib -= 1;
                    }
                }
            }
            ans.push_back(contrib);
            colors[idx] = color;
        }
        return ans;
    }
};