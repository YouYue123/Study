#include <bits/stdc++.h>
using namespace std;

// 1354. Construct Target Array With Multiple Sums [H]
// LeetCode construct-target-array-with-multiple-sums

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<int> pq;
        long long sum = 0;
        for(int t : target) {
            sum += t;
            pq.push(t);
        }
        while(pq.top() > 1) {
            auto cur = pq.top();
            pq.pop();
            long long res = sum - cur;
            if(res == 1) return true;
            if(res == 0 || res >= cur) return false;
            long long nxt = cur % res;
            if(nxt == 0) return false;
            sum = nxt + res;
            pq.push(nxt);
        }
        return true;
    }
};