#include <bits/stdc++.h>
using namespace std;

// 635. Design Log Storage System [M]
// LeetCode design-log-storage-system

enum class Type {
    Year = 0, Month = 1, Day = 2, Hour = 3, Minute = 4, Second = 5, Leaf = 6, Root = 7
};

struct Trie {
    Type type;
    int val;
    set<Trie*, bool(*)(Trie*, Trie*)> children;

    Trie(Type t, int v) : 
        type(t), 
        val(v),  
        children(
            [](Trie* a, Trie* b) { return a->val < b->val; }
        ) {}
};

class LogSystem {
private:
    Trie* root;
    map<string, int> granularity_map = {
        {"Year", 0}, 
        {"Month", 1}, 
        {"Day", 2}, 
        {"Hour", 3}, 
        {"Minute", 4}, 
        {"Second", 5}
    };

    // 将时间戳字符串解析为整数数组
    vector<int> parse(string timestamp) {
        vector<int> vals;
        stringstream ss(timestamp);
        string temp;
        while (getline(ss, temp, ':')) {
            vals.push_back(stoi(temp));
        }
        return vals;
    }

    // 收集该节点下所有的 Leaf ID
    void collect_all_ids(Trie* node, vector<int>& res) {
        if (node->type == Type::Leaf) {
            res.push_back(node->val);
            return;
        }
        for (auto child : node->children) {
            collect_all_ids(child, res);
        }
    }

    void _dfs(
        Trie* cur, 
        vector<int>& start_vals, 
        vector<int>& end_vals, 
        int depth, 
        int target_depth, 
        bool is_low_bound, 
        bool is_high_bound, 
        vector<int>& res
    ) {
        
        // 如果已经到达目标粒度层级，则收集该层节点下的所有 ID
        if (depth > target_depth) {
            collect_all_ids(cur, res);
            return;
        }

        for (auto child : cur->children) {
            int low = is_low_bound ? start_vals[depth] : -1;        // 如果已脱离下界限制，则下界为最小值
            int high = is_high_bound ? end_vals[depth] : 10000;    // 如果已脱离上界限制，则上界为最大值

            if (child->val >= low && child->val <= high) {
                // 只有当子节点值正好等于当前的边界值时，下一层才继续受边界约束
                _dfs(
                    child,
                    start_vals, 
                    end_vals, 
                    depth + 1, 
                    target_depth, 
                    is_low_bound && (child->val == low), 
                    is_high_bound && (child->val == high), 
                    res
                );
            }
        }
    }

public:
    LogSystem() {
        root = new Trie(Type::Root, -1);
    }

    void put(int id, string timestamp) {
        Trie* cur = root;
        vector<int> vals = parse(timestamp);
        
        for (int i = 0; i < vals.size(); ++i) {
            Trie dummy(Type(i), vals[i]);
            auto it = cur->children.find(&dummy);
            if (it == cur->children.end()) {
                Trie* newNode = new Trie(Type(i), vals[i]);
                cur->children.insert(newNode);
                cur = newNode;
            } else {
                cur = *it;
            }
        }
        cur->children.insert(new Trie(Type::Leaf, id));
    }

    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> res;
        int target_depth = granularity_map[granularity];
        vector<int> start_vals = parse(start);
        vector<int> end_vals = parse(end);
        
        // 初始状态：处于上下边界
        _dfs(root, start_vals, end_vals, 0, target_depth, true, true, res);
        return res;
    }
};