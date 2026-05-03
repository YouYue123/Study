// 2076. Process Restricted Friend Requests [H]
// LeetCode process-restricted-friend-requests

class UF {
private:
    vector<int> parent;
    vector<int> size;
    struct Ops {
        int u, v;
        bool united;
    };
    vector<Ops> history;
    int find(int x) {
        if(parent[x] == x) return x;
        return find(parent[x]);
    }
public:
    UF(int n) {
        size.assign(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) {
            history.emplace_back(-1, -1, false);
            return;
        };
        if(size[root_x] >= size[root_y]) {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
            history.emplace_back(root_x, root_y, true);
        } else {
            size[root_y] += size[root_x];
            parent[root_x]= root_y;
            history.emplace_back(root_y, root_x, true);
        }
    }

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }

    void rollback() {
        if(history.empty()) return;
        Ops op = history.back();
        history.pop_back();
        if(op.united) {
            size[op.u] -= size[op.v];
            parent[op.v] = op.v;
        }
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        UF uf(n);
        vector<bool> ans;
        for(auto& request : requests) {
            int u = request[0], v = request[1];
            uf.unite(u, v);
            bool invalid = false;
            for(auto& restriction : restrictions) {
                int a = restriction[0], b = restriction[1];
                if(uf.is_connected(a, b)) {
                    ans.push_back(false);
                    uf.rollback();
                    invalid = true;
                    break;
                }
            }
            if(!invalid) ans.push_back(true);
        }
        return ans;
    }
};