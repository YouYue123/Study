#include <bits/stdc++.h>
using namespace std;

// 215. Kth Largest Element in an Array [M]
// LeetCode kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left, mid, right;
        int pivot = nums[rand() % n];
        for(int num : nums) {
            if(num > pivot) {
                left.push_back(num);
            } else if(num == pivot) {
                mid.push_back(num);
            } else {
                right.push_back(num);
            }
        }
        if(left.size() >= k) {
            return findKthLargest(left, k);
        } else if(left.size() + mid.size() >= k) {
            return pivot;
        } else {
            return findKthLargest(right, k - left.size() - mid.size());
        }
    }
};