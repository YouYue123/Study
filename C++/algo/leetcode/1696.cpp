// 1696. Jump Game VI [M]
// LeetCode jump-game-vi

class MonoQueue {
    deque<int> maxQ;
    deque<int> q;
public:
    void push(int i) {
        q.push_back(i);
        while(!maxQ.empty() && maxQ.back() < i) maxQ.pop_back();
        maxQ.push_back(i);
    }
    int max() {
        return maxQ.front();
    }
    void pop() {
        if(q.front() == maxQ.front()) maxQ.pop_front();
        q.pop_front();
    }
    int size() {
        return q.size();
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        MonoQueue mq;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        mq.push(dp[0]);
        for(int i = 1; i < nums.size(); i ++) {
            dp[i] = mq.max() + nums[i];
            // cout << mq.size() << endl;
            if(mq.size() == k) mq.pop();
            mq.push(dp[i]);
        }
        // for(int i : dp) {
        //     cout << i << " ";
        // }
        // cout << endl;
        return dp[nums.size() - 1];
    }
};