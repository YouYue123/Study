// 1962. Remove Stones to Minimize the Total [M]
// LeetCode remove-stones-to-minimize-the-total

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int p : piles) pq.push(p);
        while(k --) {
            int cur = pq.top();
            pq.pop();
            pq.push(ceil((double)cur / 2));
        }
        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};