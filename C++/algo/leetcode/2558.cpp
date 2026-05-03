// 2558. Take Gifts From the Richest Pile [E]
// LeetCode take-gifts-from-the-richest-pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int g : gifts) pq.push(g);
        while(k --) {
            int cur = pq.top();
            pq.pop();
            pq.push(sqrt(cur));
        }
        long long ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};