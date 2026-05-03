#include <bits/stdc++.h>
using namespace std;

// 1425. Constrained Subsequence Sum [H]
// LeetCode constrained-subsequence-sum

class MonoQueue {
    deque<int> q;
    deque<int> maxQ;

public:
    void push(int i) {
        while (!maxQ.empty() && maxQ.back() < i) maxQ.pop_back();
        maxQ.push_back(i);
        q.push_back(i);
    }
    int max() { return maxQ.front(); }
    void pop() {
        if (q.front() == maxQ.front()) maxQ.pop_front();
        q.pop_front();
    }
    int size() { return q.size(); }
};

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        MonoQueue mq;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        mq.push(dp[0]);
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], mq.max() + nums[i]);
            if(mq.size() == k) mq.pop();
            mq.push(dp[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};