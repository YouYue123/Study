#include <bits/stdc++.h>
using namespace std;

// 1526. Minimum Number of Increments on Subarrays to Form a Target Array [H]
// LeetCode minimum-number-of-increments-on-subarrays-to-form-a-target-array

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<int> diff(target.size() + 1, 0);
        diff[0] = target[0];
        int posSum = target[0] > 0 ? target[0] : 0;
        int negSum = target[0] < 0 ? abs(target[0]) : 0;
        for(int i = 1; i < target.size(); i ++) {
            diff[i] = target[i] - target[i - 1];
            if(diff[i] > 0) {
                posSum += diff[i];
            } else {
                negSum += abs(diff[i]);
            }
        }
        return max(posSum, negSum);
    }
};