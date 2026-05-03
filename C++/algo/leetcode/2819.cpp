// 2819. Minimum Relative Loss After Buying Chocolates [H]
// LeetCode minimum-relative-loss-after-buying-chocolates

class Solution {
public:
    vector<long long> minimumRelativeLosses(vector<int>& prices, vector<vector<int>>& queries) {
        int n = prices.size();
        sort(prices.begin(), prices.end());
        vector<long long> presum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + prices[i - 1];
        }
        
        vector<long long> ans;
        for(auto& q : queries) {
            int k = q[0], m = q[1];
            
            // Binary search to find the optimal x where we buy x items and skip m-x items
            int left = 0, right = min(m, n);
            while(left < right) {
                int mid = left + (right - left) / 2;
                // The condition to check if we should increase mid
                if(prices[mid] < 2LL * k - prices[n - (m - mid)]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            // Calculate the minimum loss
            long long buy = presum[left];
            long long skip = 2LL * k * (m - left) - (presum[n] - presum[n - (m - left)]);
            ans.push_back(buy + skip);
        }
        return ans;
    }
};