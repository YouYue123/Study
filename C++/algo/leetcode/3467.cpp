#include <bits/stdc++.h>
using namespace std;

// 3467. Transform Array by Parity [E]
// LeetCode transform-array-by-parity

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int evenCount = 0;
        int oddCount = 0;
        vector<int> ans;
        for (auto num : nums) {
            if(num % 2 == 0) {
                evenCount += 1; 
            } else {
                oddCount += 1;
            }
        }
        for (int i = 0; i < evenCount + oddCount; i ++) {
            if (i < evenCount) {
                ans.push_back(0);
            } else {
                ans.push_back(1);
            }
        }
        return ans;
    }
};