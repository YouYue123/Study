#include <bits/stdc++.h>
using namespace std;

// 1298. Maximum Candies You Can Get from Boxes [H]
// LeetCode maximum-candies-you-can-get-from-boxes

class Solution {
public:
    int maxCandies(vector<int>& status, 
                   vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes
    ) {
        deque<int> q;
        for(int box : initialBoxes) {
            if(status[box] == 1) {
                q.push_front(box);
                for(int key : keys[box]) status[key] = 1;
            } else {
                q.push_back(box);
            }
        }

        int ans = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop_front();
            if(status[cur] == 1) ans += candies[cur];
            for(int key : keys[cur]) status[key] = 1;
            for(int box : containedBoxes[cur]) {
                if(status[box] == 1) q.push_front(box);
                else q.push_back(box);
            }
        }
        return ans;
    }
};