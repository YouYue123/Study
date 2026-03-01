#include <bits/stdc++.h>
using namespace std;

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int ans = INF;
        while(right < n) {
            while(1LL * nums[left] * k < nums[right]) left += 1;
            ans = min(ans, n - (right - left + 1));
            right += 1;
        }

        return ans;
    }
};