#include <bits/stdc++.h>
using namespace std;

// 373. Find K Pairs with Smallest Sums [M]
// LeetCode find-k-pairs-with-smallest-sums

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < nums1.size(); ++i) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        // Extract the smallest pairs until we have k pairs or the queue is empty.
        while (!pq.empty() && k > 0) {
            vector<int> cur = pq.top();
            pq.pop();
            
            int idx1 = cur[1]; // Index for nums1
            int idx2 = cur[2]; // Index for nums2
            ans.push_back({nums1[idx1], nums2[idx2]});
            k--;
            if (idx2 + 1 < nums2.size()) {
                pq.push({nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1});
            }
        }

        return ans;
    }
};