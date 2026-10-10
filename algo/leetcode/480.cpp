#include <bits/stdc++.h>
using namespace std;

// 480. Sliding Window Median [H]
// LeetCode sliding-window-median

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

template<typename T, typename Compare = less<T>>
struct LazyHeap {
    priority_queue<T, vector<T>, Compare> pq;
    unordered_map<T, int> removeCnt;
    int size = 0;

    void applyRemove() {
        while (!pq.empty() && removeCnt[pq.top()]) {
            removeCnt[pq.top()]--;
            pq.pop();
        }
    }

    void push(T val) { pq.push(val); size++; }
    
    void pop() { applyRemove(); pq.pop(); size--; }
    
    T top() { applyRemove(); return pq.top(); }
    
    void remove(T val) { removeCnt[val]++; size--; }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        LazyHeap<long long> small; // 最大堆，存较小的一半
        LazyHeap<long long, greater<>> large; // 最小堆，存较大的一半
        
        // 辅助函数：维持两堆平衡
        auto balance = [&]() {
            if (small.size > large.size + 1) {
                large.push(small.top()); small.pop();
            } else if (large.size > small.size) {
                small.push(large.top()); large.pop();
            }
        };

        vector<double> ans;
        for (int i = 0; i < nums.size(); ++i) {
            // 1. 插入新元素
            if (small.size == 0 || nums[i] <= small.top()) small.push(nums[i]);
            else large.push(nums[i]);
            balance();

            // 2. 移除滑出窗口的元素
            if (i >= k) {
                int out = nums[i - k];
                if (out <= small.top()) small.remove(out);
                else large.remove(out);
                balance();
            }

            // 3. 记录中位数
            if (i >= k - 1) {
                if (k % 2) ans.push_back(small.top());
                else ans.push_back(((double)small.top() + large.top()) / 2.0);
            }
        }
        return ans;
    }
};