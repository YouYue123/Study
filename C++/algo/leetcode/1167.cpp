#include <bits/stdc++.h>
using namespace std;

// 1167. Minimum Cost to Connect Sticks [M]
// LeetCode minimum-cost-to-connect-sticks

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<>> pq(sticks.begin(), sticks.end());
        int ans = 0;
        while(pq.size() > 1) {
            int next = pq.top();
            pq.pop();
            next += pq.top();
            pq.pop();
            pq.push(next);
            ans += next;
        }
        return ans;
    }
};