// 2092. Find All People With Secret [H]
// LeetCode find-all-people-with-secret

struct UF {
    vector<int> parent;
    vector<int> size;
    
    UF(int n): parent(n), size(n, 1) {
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    
    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        
        if(rootX != rootY) {
            // 小集合指向大集合
            if(size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
    
    int findRoot(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);  // 路径压缩
    }
    
    bool isConnect(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
    
    void reset(int x) {
        // 重置更复杂，需要单独处理
        // 简单实现：直接设为独立，但可能会破坏size信息
        // 对于这个问题，更适合用时间戳优化的方法
        parent[x] = x;
        size[x] = 1;
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        UF uf(n);
        uf.unite(0, firstPerson);
        sort(meetings.begin(), meetings.end(), [&](auto& a, auto& b) {
            return a[2] < b[2];
        });
        int idx = 0;
        while(idx < meetings.size()) {
            // cout << "idx: " << idx << endl;
            unordered_set<int> dict;
            int curTime = meetings[idx][2];
            // cout << "curTime: " << curTime << endl;
            while(idx < meetings.size() && meetings[idx][2] == curTime) {
                int x = meetings[idx][0], y = meetings[idx][1];
                uf.unite(x, y);
                dict.insert(x);
                dict.insert(y);
                idx += 1;
            }
            // cout << "dict: ";
            for(auto& item : dict) {
                // cout << item << " ";
                if(!uf.isConnect(0, item)) {
                    // cout << "Connected" << " ";
                    uf.reset(item);
                }
            }
            cout << endl;
        };
        vector<int> ans;
        for(int i = 0; i < n; i ++) {
            if(uf.isConnect(0, i)) ans.push_back(i);
        }
        return ans;
    }
};