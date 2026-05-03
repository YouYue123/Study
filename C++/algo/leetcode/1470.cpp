#include <bits/stdc++.h>
using namespace std;

// 1470. Shuffle the Array [E]
// LeetCode shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n, 0);
        int p1 = 0, p2 = n;
        int i = 0;
        while(p1 < n) {
            ans[i] = nums[p1];
            ans[i + 1] = nums[p2];
            p1 += 1;
            p2 += 1;
            i += 2;
        }
        return ans;
    }
};