#include <bits/stdc++.h>
using namespace std;

// 2530. Maximal Score After Applying K Operations [M]
// LeetCode maximal-score-after-applying-k-operations

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num : nums) pq.push(num);
        long long ans = 0;
        while(k --) {
            int cur = pq.top();
            pq.pop();
            ans += cur;
            pq.push(ceil((double) cur / 3));
        }
        return ans;
    }
};