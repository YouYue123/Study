#include <bits/stdc++.h>
using namespace std;

// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit [M]
// LeetCode longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

struct MonoQueue {
    queue<int> q;
    deque<int> maxQ;
    deque<int> minQ;
    void push(int x) {
        q.push(x);
        while(!maxQ.empty() && maxQ.back() < x) maxQ.pop_back();
        maxQ.push_back(x);
        while(!minQ.empty() && minQ.back() > x) minQ.pop_back();
        minQ.push_back(x);
    }
    void pop () {
        int cur = q.front();
        q.pop();
        if(maxQ.front() == cur) maxQ.pop_front();
        if(minQ.front() == cur) minQ.pop_front();
    }
    int getDiff() { return maxQ.front() - minQ.front(); }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, right = 0;
        MonoQueue mq;
        int ans = 0;
        while(right < nums.size()) {
            mq.push(nums[right]);
            while(mq.getDiff() > limit) {
                mq.pop();
                left += 1;
            }
            ans = max(ans, right - left  + 1);
            right += 1;
        }
        return ans;
    }
};