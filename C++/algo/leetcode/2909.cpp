#include <bits/stdc++.h>
using namespace std;

// 2909. Minimum Sum of Mountain Triplets II [M]
// LeetCode minimum-sum-of-mountain-triplets-ii

struct MonoQueue {
    queue<int> q;
    deque<int> minQ;
    void push(int x) {
        q.push(x);
        while(!minQ.empty() && minQ.back() > x) minQ.pop_back();
        minQ.push_back(x);
    }
    void pop() {
        int cur = q.front();
        q.pop();
        if(minQ.front() == cur) minQ.pop_front();
    }
    int min() { return minQ.front(); }

};
class Solution {
public:
    int minimumSum(vector<int>& nums) {
       // 1 3 5 6 8 
       MonoQueue q1, q2;
       q1.push(nums[0]);
       for(int i = 2; i < nums.size(); i ++) q2.push(nums[i]);
       int ans = INT_MAX;
       for(int i = 1; i < nums.size() - 1; i ++) {
            // cout << q1.min() << " " << nums[i] << " " << q2.min() << endl;
            if(nums[i] > q1.min() && nums[i] > q2.min()) {
                ans = min(ans, q1.min() + q2.min() + nums[i]);
            }
            q1.push(nums[i]);
            q2.pop();
       }
       return ans == INT_MAX ? -1 : ans;
    }
};