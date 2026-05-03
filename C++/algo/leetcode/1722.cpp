// 1722. Minimize Hamming Distance After Swap Operations [M]
// LeetCode minimize-hamming-distance-after-swap-operations

struct UF {
    vector<int> parent;
    vector<int> size;
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.resize(n);
        for(int i = 0; i < n; i ++) size[i] = 1;
    }

    void unite (int p, int q) {
        int root_p = find_root(p);
        int root_q = find_root(q);
        if(root_p == root_q) return;
        if(size[root_p] >= size[root_q]) {
            parent[root_q] = root_p;
            size[root_p] += size[root_q];
        } else {
            parent[root_p] = root_q;
            size[root_q] += root_p;
        }
    }

    bool is_connect(int p, int q) {
        return find_root(p) == find_root(q);
    }

    int find_root(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find_root(parent[x]);
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UF uf(n);
        for(auto& swap : allowedSwaps) {
            uf.unite(swap[0], swap[1]);
        }
        int ans = 0;
        unordered_map<int, vector<int>> dict;
        for(int i = 0; i < n; i ++) {
            int root = uf.find_root(i);
            dict[root].push_back(i);
        }
        for(auto& [root, idxes] : dict) {
            unordered_map<int, int> cnt; 
            int common_cnt = 0;
            for(int idx : idxes) {
                cnt[source[idx]] += 1;
            }
            for(int idx: idxes) {
                if(cnt[target[idx]] > 0) {
                    common_cnt += 1;
                    cnt[target[idx]] -= 1;
                }
            }
            // cout << common_cnt << endl;
            ans += idxes.size() - common_cnt;
        }
        return ans;
    }
};