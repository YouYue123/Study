#include <bits/stdc++.h>
using namespace std;

// 3613. Minimize Maximum Component Cost [M]
// LeetCode minimize-maximum-component-cost

struct UF {
    vector<int> parent;
    int n;
    UF(int n): n(n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX == rootY) return;
        parent[rootX] = rootY;
        n -= 1;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int left = 0, right = INT_MIN;
        for(auto& e : edges) {
            right = max(right, e[2]);
        }
        auto isValid = [&](int mid) -> bool {
            UF uf(n);
            for(const auto& e : edges) {
                if(e[2] <= mid) uf.unite(e[0], e[1]);
            }
            return uf.n <= k;
        };
        int ans = right;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};