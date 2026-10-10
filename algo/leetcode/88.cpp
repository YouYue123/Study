#include <bits/stdc++.h>
using namespace std;

// 88. Merge Sorted Array [E]
// LeetCode merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m + n - 1;
        int p1 = m - 1, p2 = n -1;
        while(p1 >= 0 && p2 >= 0) {
            if(nums1[p1] >= nums2[p2]) {
                nums1[cur] = nums1[p1];
                p1 -= 1;
            } else {
                nums1[cur] = nums2[p2];
                p2 -= 1;
            }
            cur -= 1;
        }
        while(p2 >= 0) {
            nums1[cur] = nums2[p2];
            p2 -= 1;
            cur -= 1;
        }
    }
};