#include <bits/stdc++.h>
using namespace std;

// 2966. Divide Array Into Arrays With Max Difference [M]
// LeetCode divide-array-into-arrays-with-max-difference

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // [1,3,4,8,7,9,3,5,1]
        // min 1, max 9
        vector<vector<int>> ans;
        int n = nums.size();
        int target = n / 3;
        while(ans.size() < target) {
            vector<int> temp;
            for(int j = 0; j < 3; j ++) {
                temp.push_back(nums[ans.size() * 3 + j]);
            }
            if(temp.back() - temp.front() > k) return {};
            ans.push_back(temp);
        }
        return ans;
    }
};