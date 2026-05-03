// 2931. Maximum Spending After Buying Items [H]
// LeetCode maximum-spending-after-buying-items

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto& v : values) {
            for(int item : v) pq.push(item);
        }
        long long i = 1;
        while(!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            ans += i * cur;
            i += 1;
        }
        return ans;
    }
};