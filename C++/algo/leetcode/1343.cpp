#include <bits/stdc++.h>
using namespace std;

// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold [M]
// LeetCode number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0, right = 0;
        double sum = 0;
        int ans = 0;
        while(right < arr.size()) {
            sum += arr[right];
            if(right - left + 1 > k) {
                sum -= arr[left];
                left += 1;
            }
            if(right - left + 1 == k && sum / k >= threshold) {
                ans += 1;
            }
            right += 1;
        }
        return ans;
    }
};