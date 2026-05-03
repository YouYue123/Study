#include <bits/stdc++.h>
using namespace std;

// 410. Split Array Largest Sum [H]
// LeetCode split-array-largest-sum

class Solution {
public:
    bool isValid(int x, vector<int>& nums, int k) {
        int curSum = 0;
        int curCnt = 1;
        for(int num : nums) {
            if(num > x) return false;
            if(curSum + num <= x) {
                curSum += num;
            } else {
                curSum = num;
                curCnt += 1;
            }
        }
        // cout << givenSum << " " << curCnt << endl;
        return curCnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0) + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid, nums, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};