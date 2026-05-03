// 3638. Maximum Balanced Shipments [M]
// LeetCode maximum-balanced-shipments

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int left = 0, right = 0;
        int curMax = INT_MIN;
        int ans = 0;
        while(right < weight.size()) {
            curMax = max(curMax, weight[right]);
            if(curMax > weight[right]) {
                ans += 1;
                curMax = INT_MIN;
            }
            right += 1;
        }
        return ans;
    }
};