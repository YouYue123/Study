#include <bits/stdc++.h>
using namespace std;

// 1182. Shortest Distance to Target Color [M]
// LeetCode shortest-distance-to-target-color

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> indices(4, vector<int>());
        for(int i = 0; i < colors.size(); i ++) {
            int color = colors[i];
            indices[color].push_back(i);
        }
        vector<int> ans;
        for(auto& q : queries) {
            int i = q[0], c = q[1];
            auto it = lower_bound(indices[c].begin(), indices[c].end(), i);
            // if(it != indices[c].end()) cout << *it << endl;
            int curAns = INT_MAX;
            if(it != indices[c].end()) {
                curAns = min(curAns, abs(*it - i));
            }
            if(it != indices[c].begin()) {
                curAns = min(curAns, abs(*prev(it) - i));
            }
            ans.push_back(curAns == INT_MAX ? -1 : curAns);
        }
        return ans;
    }
};