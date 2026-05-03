#include <bits/stdc++.h>
using namespace std;

// 3478. Choose K Elements With Maximum Sum [M]
// LeetCode choose-k-elements-with-maximum-sum

struct Node {
    int idx;
    int val1;
    int val2;
};
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<long long> ans(nums1.size(), 0);
        vector<Node> nodes;
        for(int i = 0; i < nums1.size(); i ++) {
            nodes.emplace_back(i, nums1[i], nums2[i]);
        }
        sort(nodes.begin(), nodes.end(), [&](const Node& a, const Node& b)  {
            return a.val1 < b.val1;
        });
        long long sum = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        int i = 1;
        pq.push(nodes[0].val2);
        sum += nodes[0].val2;
        while(i < nodes.size()) {
            if(nodes[i].val1 == nodes[i - 1].val1) {
                ans[nodes[i].idx] = ans[nodes[i - 1].idx];
            } else {
                ans[nodes[i].idx] = sum;
            }
            pq.push(nodes[i].val2);
            sum += nodes[i].val2;
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            i += 1;
        }
        return ans;
    }
};