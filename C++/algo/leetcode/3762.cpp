#include <bits/stdc++.h>
using namespace std;

// 3762. Minimum Operations to Equalize Subarrays [H]
// LeetCode minimum-operations-to-equalize-subarrays

struct Node {
    int left, right;
    int cnt;
    long long sum;
} tree [40005 * 25];
int root [40005];
int nodeIdx = 0;
int st_min[40005][17];
int st_max[40005][17];
int logs[40005];

class Solution {
    int N;
    vector<int> distinctVals;
public:
    int build(int l, int r) {
        int id = ++nodeIdx;
        tree[id].cnt = 0;
        tree[id].sum = 0;
        if(l == r) {
            tree[id].left = tree[id].right = 0;
            return id;
        }
        int mid = l + (r - l) / 2;
        tree[id].left = build(l, mid);
        tree[id].right = build(mid + 1, r);
        return id;
    }
    int update(int prev, int l, int r, int valIdx, int realVal) {
        int id = ++nodeIdx;
        tree[id] = tree[prev];
        tree[id].cnt ++;
        tree[id].sum += realVal;
        if(l == r) return id;
        int mid = l + (r - l) / 2;
        if(valIdx <= mid) {
            tree[id].left = update(tree[prev].left, l, mid, valIdx, realVal);
        } else {
            tree[id].right = update(tree[prev].right, mid + 1, r, valIdx, realVal);
        }
        return id;
    }
    pair<long long, int> query(int nodeU, int nodeV, int l, int r, int k) {
        if(l == r) return {(long long)k * distinctVals[l], distinctVals[l]};
        int leftCnt = tree[tree[nodeV].left].cnt - tree[tree[nodeU].left]. cnt;
        int mid = l + (r - l) / 2;
        if(k <= leftCnt) {
            return query(tree[nodeU].left, tree[nodeV].left, l, mid, k);
        } else {
            long long leftSum = tree[tree[nodeV].left].sum - tree[tree[nodeU].left].sum;
            auto rightAns = query(tree[nodeU].right, tree[nodeV].right, mid + 1, r, k - leftCnt);
            return {leftSum + rightAns.first, rightAns.second};
        }
    }
    void buildSparseTable(vector<int>& nums, int k) {
        logs[1] = 0;
        for(int i = 2; i <= N; i ++) logs[i] = logs[i / 2] + 1;
        for(int i = 0; i < N; i ++) {
            st_min[i][0] = nums[i] % k;
            st_max[i][0] = nums[i] % k;
        }
        for(int j = 1; j < 17; j++) {
            for(int i = 0; i + (1 << j) <= N; i ++) {
                st_min[i][j] = min(st_min[i][j - 1] , st_min[i + (1 << (j - 1))][j - 1]);
                st_max[i][j] = max(st_max[i][j - 1] , st_max[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    bool checkModulo(int l, int r) {
        int j = logs[r - l + 1];
        int minMod = min(st_min[l][j], st_min[r - (1 << j) + 1][j]);
        int maxMod = max(st_max[l][j], st_max[r - (1 << j) + 1][j]);
        return minMod == maxMod;
    }
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        N = nums.size();
        nodeIdx = 0;
        buildSparseTable(nums, k);
        distinctVals = nums;
        sort(distinctVals.begin(), distinctVals.end());
        distinctVals.erase(
            unique(distinctVals.begin(), distinctVals.end()),
            distinctVals.end()
        );
        int M = distinctVals.size();
        root[0] = build(0, M-1);
        for(int i = 0; i < N; i ++) {
            int rank = lower_bound(distinctVals.begin(), distinctVals.end(), nums[i]) - distinctVals.begin();
            root[i + 1] = update(root[i], 0, M - 1, rank, nums[i]);
        }
        vector<long long> ans;
        for(auto& q: queries) {
            int L = q[0], R = q[1];
            if(!checkModulo(L, R)) {
                ans.push_back(-1);
                continue;
            }
            int len = R - L + 1;
            int k_median = (len + 1) / 2;
            auto result = query(root[L], root[R + 1], 0 , M - 1, k_median);
            long long sumLeft = result.first;
            long long medianVal = result.second;
            long long sumTotal = tree[root[R + 1]].sum - tree[root[L]].sum;
            long long sumRight = sumTotal - sumLeft;
            long long cntLeft = k_median;
            long long cntRight = len - k_median;
            long long cost = (cntLeft * medianVal - sumLeft) + (sumRight - cntRight * medianVal);
            ans.push_back(cost / k);
        }
        return ans;
        //1 4 7 10 13
        // 1 1 1  1
        // 1 2 3 4
        // int n = nums.size();
        // vector<int> rem(n);
        // vector<long long> val(n);
        // for(int i = 0; i < n; i ++) {
        //     rem[i] = nums[i] % k;
        //     val[i] = nums[i] / k;
        // }
        // vector<int> remPrefix(n + 1, 0);
        // for(int i = 0; i < n; i ++) {
        //     remPrefix[i + 1] = remPrefix[i] + rem[i];
        // }
        // vector<int> indices(n, 0);
        // sort(indices.begin(), indices.end(), [&](int i, int j) {
        //     return val[i] < val[j];
        // });
        // vector<int> pos(n);
        // for(int i = 0; i < n; i ++) pos[indices[i]] = i;
        // vector<long long> presum(n + 1, 0);
        // for(int i = 0; i < n; i ++) {
        //     presum[i + 1] = presum[i] + val[indices[i]];
        // }
        // vector<long long> ans;
        // for(auto& q : queries) {
        //     int l = q[0], r = q[1];
        //     int len = r - l + 1;
        //     bool feas = true;
        //     for(int i = l + 1; i <= r; i ++) {
        //         if(rem[i] != rem[l]) {
        //             feas = false;
        //             break;
        //         }
        //     }
        //     if(!feas) {
        //         ans.push_back(-1);
        //         continue;                
        //     }
        //     if(len == 1) {
        //         ans.push_back(0);
        //         continue;
        //     }
        //     vector<long long> rangedVals;
        //     for(int i = l; i <= r; i ++) rangedVals.push_back(val[i]);
        //     sort(rangedVals.begin(), rangedVals.end());
        //     long long median = rangedVals[len / 2];
        //     // cout << median << endl;
        //     long long temp = 0;
        //     for(int i = l; i <= r; i++) temp += abs(val[i] - median);
        //     ans.push_back(temp);
        // }
        // return ans;
    }
};