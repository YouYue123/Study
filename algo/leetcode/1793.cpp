#include <bits/stdc++.h>
using namespace std;

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int L = nums[k];
        int cur_min = nums[k];
        for(int i = k - 1; i >= 0; i --) {
            int len = (k - i + 1);
            cur_min = min(cur_min, nums[i]);
            L = max(L, cur_min * len);
        }
        int R = nums[k];
        cur_min = nums[k];
        for(int i = k + 1; i < n; i ++) {
            int len = (i - k + 1);
            cur_min = min(cur_min, nums[i]);
            R = max(R, cur_min * len);
        }
        int M = nums[k];
        int left = k, right = k;
        cur_min = nums[k];
        while(left - 1 >= 0 || right + 1< n) {
            if(right + 1 == n || (left - 1 >= 0 && nums[left - 1] >= nums[right + 1])) {
                left -= 1;
                cur_min = min(cur_min, nums[left]);
            } else {
                right += 1;
                cur_min = min(cur_min, nums[right]);
            }
            int len = right - left + 1;
            M = max(M, cur_min * len);
        }
        return max({ L, M, R });
    }
};