#include <bits/stdc++.h>
using namespace std;

// 3607. Power Grid Maintenance [M]
// LeetCode power-grid-maintenance

class UF {
    vector<int> parent;
public:
    UF (int size) {
        parent.resize(size);
        for(int i = 0; i < size; i ++) parent[i] = i;
    };
    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX == rootY) return;
        parent[rootX] = rootY;
    };
    int findRoot(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, int> inorder;
        UF uf(c + 1);
        for(auto& c :connections) {
            uf.unite(c[0], c[1]);
            uf.unite(c[1], c[0]);
        }
        unordered_set<int> offline;
        using minHeap = priority_queue<int, vector<int>, greater<>>;
        unordered_map<int, minHeap> pqs;
        for(int i = 1; i <= c; i ++) {
            int root = uf.findRoot(i);
            // cout << "i " << i << " root " << root << endl;
            if(!pqs.contains(root)) pqs[root] = minHeap();
            pqs[root].push(i);
        }
        vector<int> ans;
        for(auto& q : queries) {
            int op = q[0];
            int x = q[1];
            if(op == 1) {
                if(offline.contains(x)) {
                    // cout << "offline: " << x << endl;
                    int root = uf.findRoot(x);
                    auto& pq = pqs[root];
                    bool ok = false;
                    while(!pq.empty()) {
                        if(offline.contains(pq.top())) pq.pop();
                        else {
                            ok = true;
                            ans.push_back(pq.top());
                            break;
                        }
                    }
                    if(!ok) ans.push_back(-1);
                } else {
                    ans.push_back(x);
                }
            } else {
                offline.insert(x);
            }
        }
        return ans;
    }
};