#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        ll cur_max = 1; // [0, cur_max - 1] can be all covered
        ll ans = 0;
        int i = 0;
        while(cur_max <= n) {
            if(i < nums.size() && nums[i] <= cur_max) {
                cur_max += nums[i];
                i += 1;
            } else {
                cur_max += cur_max;
                ans += 1;
            }
        }
        return ans;
    }
};