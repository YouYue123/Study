#include <bits/stdc++.h>
using namespace std;

// 1287. Element Appearing More Than 25% In Sorted Array [E]
// LeetCode element-appearing-more-than-25-in-sorted-array

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> candidates = { arr[n / 4], arr[n / 2], arr[3*n / 4]};
        for(int candidate : candidates) {
            auto it1 = lower_bound(arr.begin(), arr.end(), candidate);
            auto it2 = lower_bound(arr.begin(), arr.end(), candidate + 1) - 1;
            if(it2 - it1 + 1 > n / 4)  {
                return candidate;
            }
        }  
        return -1;
    }
};