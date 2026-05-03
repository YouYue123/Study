#include <bits/stdc++.h>
using namespace std;

// 531. Lonely Pixel I [M]
// LeetCode lonely-pixel-i

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int, int> rowDict;
        unordered_map<int, int> colDict;
        int m = picture.size();
        int n = picture[0].size();
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j ++) {
                if(picture[i][j] == 'B') {
                    rowDict[i] += 1;
                    colDict[j] += 1;
                }
            }
        }
        // for(int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j ++) {
        //         cout << "row: " << i << " col: " << j 
        //         << " row val: " << rowDict[i] << " col val: " << colDict[j] << endl;
        //     }
        // }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j ++) {
                if (picture[i][j] == 'B' && rowDict[i] == 1 && colDict[j] == 1) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};