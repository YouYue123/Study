#include <bits/stdc++.h>
using namespace std;

// 3608. Minimum Time for K Connected Components [M]
// LeetCode minimum-time-for-k-connected-components

struct UF {
    vector<int> parent;
    int n;
    UF(int n): n(n), parent(n) {
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }
    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX == rootY) return;
        parent[rootY] = rootX;
        n -= 1;
    }
};
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int left = 0, right = 1e9;
        auto isValid = [&] (int mid) {
            UF uf(n);
            for(auto & e : edges) {
                if(e[2] > mid) uf.unite(e[0], e[1]);
            }
            return uf.n >= k;
        };
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};