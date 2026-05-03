#include <bits/stdc++.h>
using namespace std;

// 2542. Maximum Subsequence Score [M]
// LeetCode maximum-subsequence-score

struct Pair {
    int num1;
    int num2;
    Pair(int _num1, int _num2): num1(_num1), num2(_num2){};
    // Define operator> for comparison
    bool operator>(const Pair& other) const {
        if(num2 == other.num2) {
            return num1 > other.num1;
        }
        return num2 > other.num2;
    }
};

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<Pair> pairs;
        int n = nums1.size();
        for(int i = 0; i < n ; i ++) pairs.push_back(Pair(nums1[i], nums2[i]));
        sort(pairs.begin(), pairs.end(), greater<Pair>());
        long long topKSum = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for(int i = 0; i < k ; i ++) {
            topKSum += pairs[i].num1;
            pq.push(pairs[i].num1);
        }
        long long ans = topKSum * pairs[k - 1].num2;
        for(int i = k; i < n; i ++) {
            topKSum = topKSum + pairs[i].num1 - pq.top();
            pq.pop();
            pq.push(pairs[i].num1);
            ans = max(ans, topKSum * pairs[i].num2);
        } 
        return ans;
    }
};