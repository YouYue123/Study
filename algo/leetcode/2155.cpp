#include <bits/stdc++.h>
using namespace std;

// 2155. All Divisions With the Highest Score of a Binary Array [M]
// LeetCode all-divisions-with-the-highest-score-of-a-binary-array

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int rightOne = accumulate(nums.begin(),nums.end(),0);
        int leftZero = 0;
        int maxScore = 0;
        vector<int> ans;
        for (int i = 0; i <= nums.size(); i ++) {
            if (rightOne + leftZero > maxScore) {
                maxScore = rightOne + leftZero;
                ans.clear();
                ans.push_back(i);
            } else if (rightOne + leftZero == maxScore) {
                ans.push_back(i);
            }
            if(i != nums.size()) {
                if (nums[i] == 0) leftZero += 1;
                if (nums[i] == 1) rightOne -= 1;
            }
        }
        return ans;
    }
};