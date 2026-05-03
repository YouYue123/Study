#include <bits/stdc++.h>
using namespace std;

// 3066. Minimum Operations to Exceed Threshold Value II [M]
// LeetCode minimum-operations-to-exceed-threshold-value-ii

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq;
        for(int num : nums) {
            pq.push(num);
        }
        int ans = 0;
        while(pq.size() >= 2 && pq.top() < k) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            pq.push(min(a, b) * 2 + max(a, b));
            ans += 1;
        }
        return ans;
    }
};