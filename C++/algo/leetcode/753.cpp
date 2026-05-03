// 753. Cracking the Safe [H]
// LeetCode cracking-the-safe

class Solution {
public:
    // void printAdjacencyList(const unordered_map<string, vector<string>>& g) {
    //     cout << "--- 状态转移图 (邻接表) ---" << endl;
    //     for (auto const& [u, neighbors] : g) {
    //         cout << "[" << u << "] -> { ";
    //         for (int i = 0; i < neighbors.size(); ++i) {
    //             cout << neighbors[i] << (i == neighbors.size() - 1 ? "" : ", ");
    //         }
    //         cout << " }" << endl;
    //     }
    // }
    string crackSafe(int n, int k) {
        if (n == 1) {
            string res = "";
            for (int i = 0; i < k; i++) res += to_string(i);
            return res;
        }
        unordered_map<string, vector<string>> g;
        vector<string> nodes;
        queue<string> q;
        for(int i = 0; i < k; i ++) q.push(to_string(i));
        int depth = 1;
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i ++) {
                auto cur = q.front();
                q.pop();
                if(depth < n - 1) {
                    for(int j = 0; j < k; j ++)  q.push(cur + to_string(j));
                } else {
                    nodes.push_back(cur);
                }
            }
            depth += 1;
        }
        for(const string& u : nodes) {
            for(int i = 0; i < k; i ++) {
                string v = u.substr(1) + to_string(i);
                g[u].push_back(v);
            }
        }
        // printAdjacencyList(g);
        vector<string> ans;
        auto dfs = [&] (this auto&& dfs, const string& u) -> void {
            while(!g[u].empty()) {
                auto v = g[u].back();
                g[u].pop_back();
                dfs(v);
            }
            ans.push_back(u);
        };
        string start_node(n - 1, '0');
        dfs(start_node);
        reverse(ans.begin(), ans.end());
        string final_ans = start_node; 
        for (int i = 1; i < ans.size(); i++) {
            final_ans += ans[i].back();
        }
        return final_ans;
    }
};