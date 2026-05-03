// 3275. K-th Nearest Obstacle Queries [M]
// LeetCode k-th-nearest-obstacle-queries

struct Node {
    double x;
    double y;
    double dist () const {
        return abs(x) + abs(y);
    }
    bool operator < (const Node& other) const {
        return dist() < other.dist();
    }
     bool operator > (const Node& other) const {
        return dist() > other.dist();
    }

};
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<Node> pq;
        vector<int> ans;
        for(auto& q : queries) {
            pq.emplace(q[0], q[1]);
            if(pq.size() > k) {
                pq.pop();
            }
            if(pq.size() == k) ans.push_back(pq.top().dist());
            else ans.push_back(-1);
        }
        return ans;
    }
};