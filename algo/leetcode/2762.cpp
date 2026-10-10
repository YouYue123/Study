#include <bits/stdc++.h>
using namespace std;

// 2762. Continuous Subarrays [M]
// LeetCode continuous-subarrays

struct MonoQueue {
    deque<int> q;
    deque<int> maxQ;
    deque<int> minQ;
    void push(int x) {
        q.push_back(x);
        while(!maxQ.empty() && maxQ.back() < x) maxQ.pop_back();
        maxQ.push_back(x);
        while(!minQ.empty() && minQ.back() > x) minQ.pop_back();
        minQ.push_back(x);
    }
    void pop() {
        int item = q.front();
        q.pop_front();
        if(maxQ.front() == item) maxQ.pop_front();
        if(minQ.front() == item) minQ.pop_front();
    }
    int maxDiff () { return abs(maxQ.front() - minQ.front()); }
};
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0, right = 0;
        MonoQueue mq;
        long long ans = 0;
        while(right < nums.size()) {
            mq.push(nums[right]);
            while(mq.maxDiff() > 2) {
                mq.pop();
                left += 1;
            }
            // cout << left << " " << right << endl;
            ans += right - left + 1;
            right += 1;
        }
        return ans;
    }
};