// 862. Shortest Subarray with Sum at Least K [H]
// LeetCode shortest-subarray-with-sum-at-least-k

class MonoQueue {
    deque<int> q;
    deque<int> minQ;
public:
    void push(int i) {
        q.push_back(i);
        while(!minQ.empty() && minQ.back() > i) minQ.pop_back();
        minQ.push_back(i);
    }
    int min() { return minQ.front(); }
    void pop() {
        if(q.front() == minQ.front()) minQ.pop_front();
        q.pop_front();
    }
    bool empty() { return q.empty(); }
};
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long> preSum(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i ++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        int left = 0, right = 0;
        MonoQueue q;
        int ans = INT_MAX;
        while(right < preSum.size()) {
            q.push(preSum[right]);
            while(!q.empty() && preSum[right] - q.min() >= k) {
                if(preSum[right] - preSum[left] >= k) {
                    // cout << left << " " << right << endl;
                    // cout << preSum[right] - preSum[left] << endl;
                    ans = min(ans, right - left);
                }
                q.pop();
                left += 1;
            }
            right += 1;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};