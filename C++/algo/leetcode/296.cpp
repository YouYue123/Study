
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minTotalDistance(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            vector<int> x_list;
            vector<int> y_list;
            for(int x = 0; x < m; x ++) {
                for(int y = 0; y < n; y ++) {
                    if(grid[x][y] == 1) {
                        x_list.push_back(x);
                        y_list.push_back(y);
                    }
                }
            }
            int cnt  = x_list.size();
            sort(x_list.begin(), x_list.end());
            sort(y_list.begin(), y_list.end());
    
            int t_x = x_list[cnt / 2], t_y = y_list[cnt / 2];
            // cout << t_x << " " << t_y << endl;
            int ans = 0;
            for(int x = 0; x < m; x ++) {
                for(int y = 0; y < n; y ++) {
                    if(grid[x][y] == 1) {
                        ans += abs(x - t_x) + abs(y - t_y);
                    }
                }
            }
            return ans;
        }
    };