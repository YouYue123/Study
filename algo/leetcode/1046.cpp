#include <bits/stdc++.h>
using namespace std;

// 1046. Last Stone Weight [E]
// LeetCode last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int s : stones) pq.push(s);
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int diff = abs(a - b);
            if(diff != 0) pq.push(diff);
        }
        return pq.empty() ? 0 : pq.top();
    }
};