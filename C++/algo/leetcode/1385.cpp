#include <bits/stdc++.h>
using namespace std;

// 1385. Find the Distance Value Between Two Arrays [E]
// LeetCode find-the-distance-value-between-two-arrays

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for(auto item1: arr1) {
            // First element in arr2 >= item1
            auto it = lower_bound(arr2.begin(), arr2.end(), item1);
            if(it != arr2.end() && (*it - item1) <= d) continue;
            if(it != arr2.begin() && (item1 - *prev(it) <= d)) continue;
            ans += 1;
        }
        return ans;
    }
};