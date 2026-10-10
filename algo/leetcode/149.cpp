#include <bits/stdc++.h>
using namespace std;

// 149. Max Points on a Line [H]
// LeetCode max-points-on-a-line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(), points.end());
        for(int i = 0; i < points.size(); i ++) {
            for (int j = i + 1; j < points.size(); j ++) {
                int deltaX = points[j][0] - points[i][0];
                int deltaY = points[j][1] - points[i][1];
                // cout << "starting point 1" << endl;
                // cout << "x: " << points[i][0]<< " y: " << points[i][1] << endl;
                // cout << "starting point 2" << endl;
                // cout << "x: " << points[j][0]<< " y: " << points[j][1] << endl;
                int count = 2;
                for(int k = j + 1; k < points.size(); k ++) {
                    // if(k == j || k == i) continue;
                    //  cout << "checking: " << endl;
                    //  cout << "x: " << points[k][0]<< " y: " << points[k][1] << endl;
                    if(
                      atan2(points[k][0] - points[j][0],points[k][1] - points[j][1]) ==
                      atan2(deltaX, deltaY)
                    ) {
                        // cout << "found" << endl;
                        count += 1;
                    }
                }
                ans = max(count, ans);
            }
        }
        // 1 4
        // 2 3
        // 3 2
        // 4 1
        return ans;
    }
};