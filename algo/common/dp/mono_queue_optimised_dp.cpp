#include <bits/stdc++.h>

using namespace std;
// LC 3568
// https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/
int MOD = 1e9 + 7;
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        // 将前 i 个元素（nums[0]到nums[i-1]）分割成合法子数组的方案数。
        vector f(n + 1, 0);
        deque<int> minQ, maxQ;
        f[0] = 1;
        long long sumF = 0;
        int left = 0;
        for(int i = 0; i < nums.size(); i ++) {
            sumF += f[i];
            while(minQ.size() > 0 && nums[minQ.back()] >= nums[i]) minQ.pop_back();
            minQ.push_back(i);
            while(maxQ.size() > 0 && nums[maxQ.back()] <= nums[i]) maxQ.pop_back();
            maxQ.push_back(i);
            while(nums[maxQ.front()] - nums[minQ.front()] > k) {
                sumF -= f[left];
                left += 1;
                if(maxQ.front() < left) maxQ.pop_front();
                if(minQ.front() < left) minQ.pop_front();  
            }
            f[i + 1] = sumF % MOD;
        }
        return f[n];
    }
};