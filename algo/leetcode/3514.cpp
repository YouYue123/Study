#include <bits/stdc++.h>
using namespace std;

// 3514. Number of Unique XOR Triplets II [M]
// LeetCode number-of-unique-xor-triplets-ii

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique_xors;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                unique_xors.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> ans;
        for(int num : nums) ans.insert(num);
        for(int k = 0; k < nums.size(); k++) {
            for(int item : unique_xors) {
                ans.insert(item ^ nums[k]);
            }
        }
        return ans.size();
    }
};