#include <bits/stdc++.h>
using namespace std;

// 4. Median of Two Sorted Arrays [H]
// LeetCode median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int total_len = len1 + len2;
        auto dfs = [&] (this auto&& dfs, int start1, int end1, int start2, int end2, int k) -> double {
            if(start1 > end1) return nums2[k - start1];
            if(start2 > end2) return nums1[k - start2];
            int mid1 = start1 + (end1 - start1) / 2;
            int mid2 = start2 + (end2 - start2) / 2;
            int val1 = nums1[mid1];
            int val2 = nums2[mid2];
            if(mid1 + mid2 < k) {
                if(val1 > val2) {
                    return dfs(start1, end1, mid2 + 1, end2, k);
                } else {
                    return dfs(mid1 + 1, end1, start2, end2, k);
                }
            } else {
                if(val1 > val2) {
                    return dfs(start1, mid1 - 1, start2, end2, k);
                } else {
                    return dfs(start1, end1, start2, mid2 - 1, k);
                }
            }
        };
        if(total_len % 2 == 1) {
            return dfs(0, len1 - 1, 0, len2 - 1, total_len / 2);
        } else {
            return (
                dfs(0, len1 - 1, 0, len2 - 1, total_len / 2 ) +
                dfs(0, len1 - 1, 0, len2 - 1, total_len / 2 - 1)
            ) / 2.0;
        }
    }
};