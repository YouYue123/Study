#include <bits/stdc++.h>
using namespace std;

// 3532. Path Existence Queries in a Graph I [M]
// LeetCode path-existence-queries-in-a-graph-i

class UF {
  public:
    vector<int> parent;
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    void union_(int p, int q) {
        int rootP = findRoot(p);
        int rootQ = findRoot(q);
        if(rootP == rootQ) return;
        parent[rootP] = rootQ;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        int root = findRoot(parent[x]);
        parent[x] = root;
        return root;
    }
    int isConnected(int p, int q) {
        return findRoot(p) == findRoot(q);
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        auto uf = UF(n);
        for(int i = 1; i < nums.size(); i ++) {
            if(abs(nums[i] - nums[i - 1]) <= maxDiff) {
                uf.union_(i, i - 1);
            }
        }
        vector<bool> ans;
        for(auto& q : queries) {
            ans.push_back(uf.isConnected(q[0], q[1]));
        }
        return ans;
    }
};