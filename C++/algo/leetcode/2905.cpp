#include <bits/stdc++.h>
using namespace std;

// 2905. Find Indices With Index and Value Difference II [M]
// LeetCode find-indices-with-index-and-value-difference-ii

#include <vector>
#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;

struct Node {
    int val;
    int idx;
};

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idxDiff, int valDiff) {
        Node curMin = {INT_MAX, -1};
        Node curMax = {INT_MIN, -1};
        unordered_map<int, pair<Node, Node>> dict;
        
        for (int i = 0; i < nums.size(); i++) {
            // Update current min and max
            if (nums[i] < curMin.val) {
                curMin = {nums[i], i};
            }
            if (nums[i] > curMax.val) {
                curMax = {nums[i], i};
            }
            
            // Store the current min and max up to index i
            dict[i] = {curMin, curMax};
            if (i - idxDiff >= 0) {
                int j = i - idxDiff;
                Node preMin = dict[j].first;
                Node preMax = dict[j].second;
                
                if (abs(nums[i] - preMin.val) >= valDiff) {
                    return {preMin.idx, i};
                }
                if (abs(preMax.val - nums[i]) >= valDiff) {
                    return {preMax.idx, i};
                }
            }
        
        }
        
        return {-1, -1};
    }
};