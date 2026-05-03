#include <bits/stdc++.h>
using namespace std;

// 973. K Closest Points to Origin [M]
// LeetCode k-closest-points-to-origin

struct Node {
    int x;
    int y;
    
    bool operator< (const Node& other) const {
        return get_dist() < other.get_dist();
    }

    double get_dist() const {
        return sqrt(x * x + y * y);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Node> pq;
        for(auto& p : points) {
            int x = p[0], y = p[1];
            pq.emplace(x, y);
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back({ pq.top().x, pq.top().y });
            pq.pop();
        }
        return ans;
    }
};