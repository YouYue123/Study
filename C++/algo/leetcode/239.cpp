// 239. Sliding Window Maximum [H]
// LeetCode sliding-window-maximum

struct MonoQueue {
    deque<int> q;
    void push(int x) {
        while(!q.empty() && q.back() < x) {
            q.pop_back();
        }
        q.push_back(x);
    }
    void pop(int x) {
        if(q.front() == x) q.pop_front();
    }

    int get_max () {
        return q.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        MonoQueue mq;
        vector<int> ans;
        while(right < n) {
            mq.push(nums[right]);
            if(right - left + 1 > k) {
                mq.pop(nums[left]);
                left += 1;
            }
            if(right - left + 1 == k) {
                ans.push_back(mq.get_max());
            }
            right += 1;
        }
        return ans;
    }
};