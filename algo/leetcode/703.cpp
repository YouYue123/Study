#include <bits/stdc++.h>
using namespace std;

// 703. Kth Largest Element in a Stream [E]
// LeetCode kth-largest-element-in-a-stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
    KthLargest(int k, vector<int>& nums): k(k) {
        for(int num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
     }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */