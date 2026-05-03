#include <bits/stdc++.h>
using namespace std;

// 3073. Maximum Increasing Triplet Value [M]
// LeetCode maximum-increasing-triplet-value


class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        set<int> preSet;
        preSet.insert(nums[0]);
        vector<int> postMax(nums.size(), 0);
        for(int i = nums.size() - 2; i >=0; i--) {
            postMax[i] = max(postMax[i + 1], nums[i + 1]);
        }
        // for(int i = 0; i < nums.size(); i ++) {
        //     cout << postMax[i] << endl;
        // }
        int ans = INT_MIN;
        for(int i = 1; i < nums.size() - 1; i ++) {
            // cout << i << endl;
            if(nums[i] < postMax[i]) {
                // cout << "max pass" << endl;
                auto it = preSet.lower_bound(nums[i]);
                // cout << *it << endl;
                // cout << *preSet.begin() << endl;
                if(it != preSet.begin()) {
                    // cout <<  *prev(it) << " " << nums[i] << " " << postMax[i] << endl;
                    ans = max(ans, *prev(it) + postMax[i] - nums[i]);
                }
            }
            preSet.insert(nums[i]);
        }
        return ans;
    }
};