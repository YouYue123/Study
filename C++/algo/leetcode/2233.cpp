// 2233. Maximum Product After K Increments [M]
// LeetCode maximum-product-after-k-increments

int MOD = 1e9 + 7;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for(int num : nums) {
            pq.push(num);
        }
        while(k--) {
            int cur = pq.top();
            pq.pop();
            pq.push(cur + 1);
        }
        long long ans = 1;
        while(!pq.empty()) {
            ans = (ans * pq.top()) % MOD; 
            pq.pop();
        }
        return ans;
    }
};