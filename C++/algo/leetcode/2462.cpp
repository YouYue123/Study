// 2462. Total Cost to Hire K Workers [M]
// LeetCode total-cost-to-hire-k-workers

struct Node {
    int idx;
    int val;
    bool operator > (const Node& other) const {
        if(val == other.val) return idx > other.idx;
        return val > other.val;
    }
};
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        int left = 0, right = costs.size() - 1;
        while(left < candidates) {
            pq.emplace(left, costs[left]);
            left += 1;
        }
        while(costs.size() - right - 1 < candidates && left <= right) {
            pq.emplace(right, costs[right]);
            right -= 1;
        }
        // cout << pq.size() << endl;
        // cout << left << " " << right << endl;
        long long ans = 0;
        while(k--) {
            // cout << pq.top().val << endl;
            auto cur = pq.top();
            ans += cur.val;
            pq.pop();
            if(left > right) continue;
            if(cur.idx <= right) {
                // cout << "enque left : " << costs[left] << endl;
                pq.emplace(left, costs[left]);
                left += 1;
            } else {
                // cout << "enque right : " << costs[right] << endl;
                pq.emplace(right, costs[right]);
                right -= 1;
            }
        }
        return ans;
    }
};