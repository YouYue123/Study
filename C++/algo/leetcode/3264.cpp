// 3264. Final Array State After K Multiplication Operations I [E]
// LeetCode final-array-state-after-k-multiplication-operations-i

struct Node {
    int val;
    int idx;
    bool operator < (const Node& other) const {
        if(val == other.val) {
            return idx < other.idx; 
        } else {
            return val < other.val;
        }
    }
    bool operator > (const Node& other) const {
        if(val == other.val) {
            return idx > other.idx; 
        } else {
            return val > other.val;
        }
    }
};
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<Node, vector<Node>, greater<>>  pq;
        for(int i = 0; i < nums.size(); i ++) {
            pq.emplace(nums[i], i);
        }
        while(k--) {
            auto cur = pq.top();
            pq.pop();
            pq.emplace(cur.val * multiplier, cur.idx);
        } 
        vector<int> ans (nums.size(), 0);
        while(!pq.empty()) {
            ans[pq.top().idx] = pq.top().val;
            pq.pop();
        }
        return ans;
    }
};