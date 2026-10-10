#include <bits/stdc++.h>
using namespace std;

// 841. Keys and Rooms [M]
// LeetCode keys-and-rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        unordered_set<int> visit;
        visit.insert(0);
        while(!q.empty() && visit.size() < n) {
            int cur = q.front();
            q.pop();
            for(int nxt : rooms[cur]) {
                if(visit.contains(nxt)) continue;
                visit.insert(nxt);
                q.push(nxt);
            }
        }
        return visit.size() == n;
    }
};