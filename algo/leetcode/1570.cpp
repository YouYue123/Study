#include <bits/stdc++.h>
using namespace std;

// 1570. Dot Product of Two Sparse Vectors [M]
// LeetCode dot-product-of-two-sparse-vectors

class SparseVector {

public:
    unordered_map<int, int> dict;
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] != 0) dict[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for(auto& [idx, num] : dict) {
            if(vec.dict.contains(idx)) {
                ans += dict[idx] * vec.dict[idx];
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);