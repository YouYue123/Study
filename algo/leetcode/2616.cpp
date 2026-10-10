#include <bits/stdc++.h>
using namespace std;

// 2616. Minimize the Maximum Difference of Pairs [M]
// LeetCode minimize-the-maximum-difference-of-pairs

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()) + 1;
        sort(nums.begin(), nums.end());
        auto isValid = [&](int x) -> bool {
            int cnt = 0;
            int i = 0;
            while(i < nums.size() - 1) {
                if(nums[i + 1] - nums[i] <= x) {
                    cnt += 1;
                    i += 2;
                } else {
                    i += 1;
                }
            }
            // cout << cnt << " " << p << endl;
            return cnt >= p;
        };
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