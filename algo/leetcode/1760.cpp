#include <bits/stdc++.h>
using namespace std;

// 1760. Minimum Limit of Balls in a Bag [M]
// LeetCode minimum-limit-of-balls-in-a-bag

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        auto isValid = [&](int x) -> bool {
            int opsCnt = 0;
            for(int num : nums) {
                if(num <= x) continue;
                opsCnt += (num - 1) / x;
            }
            // cout << x << " " << opsCnt << endl;
            return opsCnt <= maxOperations;
        };
        int left = 1;
        int right = *max_element(nums.begin(), nums.end()) + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};