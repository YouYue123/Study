#include <bits/stdc++.h>
using namespace std;

// 1802. Maximum Value at a Given Index in a Bounded Array [M]
// LeetCode maximum-value-at-a-given-index-in-a-bounded-array

class Solution {
public: 
    // Helper function to check if 'givenX' is a valid value at 'index' given constraints
    bool isValid(int givenX, int n, int index, int maxSum) {
        // Calculate the sum of elements to the left of 'index'
        int leftCount = index; // Number of elements to the left
        long long leftSum = 0;
        
        if (givenX > leftCount) {
            // If x is larger than leftCount, we can form a complete arithmetic sequence
            // Sequence: [x-leftCount, x-leftCount+1, ..., x-1]
            leftSum = (long long)(givenX - 1 + givenX - leftCount) * leftCount / 2;
        } else {
            // If x is smaller, the sequence starts with 1's after the decreasing part
            // Sum of [1, 2, ..., x-1] plus remaining (leftCount - (x-1)) 1's
            leftSum = (long long)(givenX - 1 + 1) * (givenX - 1) / 2 + (leftCount - (givenX - 1));
        }
        
        // Calculate the sum of elements to the right of 'index' (same logic as left)
        int rightCount = n - index - 1; // Number of elements to the right
        long long rightSum = 0;
        
        if (givenX > rightCount) {
            // Complete decreasing sequence to the right
            rightSum = (long long)(givenX - 1 + givenX - rightCount) * rightCount / 2;
        } else {
            // Partial sequence with 1's filling the rest
            rightSum = (long long)(givenX - 1 + 1) * (givenX - 1) / 2 + (rightCount - (givenX - 1));
        }
        
        // Check if total sum (left + x + right) is within maxSum
        return leftSum + rightSum + givenX <= maxSum;
    }

    // Main function to find the maximum valid value at index
    int maxValue(int n, int index, int maxSum) {
        // Binary search between 0 and maxSum+1 (exclusive upper bound)
        int left = 0, right = maxSum + 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2; // Prevent overflow
            
            if (isValid(mid, n, index, maxSum)) {
                // If mid is valid, search for higher values
                left = mid + 1;
            } else {
                // Otherwise, search lower values
                right = mid;
            }
        }
        
        // The loop exits with left = first invalid value, so we return left-1
        return left - 1;
    }
};