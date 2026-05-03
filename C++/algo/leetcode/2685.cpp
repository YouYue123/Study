// 2685. Count the Number of Complete Components [M]
// LeetCode count-the-number-of-complete-components

class UF {
private:
    vector<int> parent;
    vector<int> size;
public:
    UF(int n) {
        size.assign(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        } else {
            parent[root_x] = root_y;
            size[root_y] += size[root_x];
        }
    }
    vector<int> get_size() {
        return size;
    }
};
class Solution {
 
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UF uf(n);
        unordered_map<int, int> cnt;
        for(auto& edge : edges) uf.unite(edge[0], edge[1]);
        for(auto& edge: edges) cnt[uf.find(edge[0])] += 1;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            if(uf.find(i) == i) {
                int node_cnt = uf.get_size()[i];
                int target = (node_cnt * (node_cnt - 1)) / 2;
                if(target == cnt[i]) ans += 1;
            }
        }
        return ans;
    }
    
};