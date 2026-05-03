// 2049. Count Nodes With the Highest Score [M]
// LeetCode count-nodes-with-the-highest-score

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        unordered_map<int, vector<int>> g;
        for(int i = 0; i < n; i ++) {
            if(parents[i] >= 0) g[parents[i]].push_back(i);
        }
        vector<int> size(n, 0);    
        long long max_score = 0;
        int ans = 0;
        auto calc_root = [&] (this auto&& dfs, int cur) -> void {
            size[cur] = 1;
            long long cur_score = 1;
            for(auto nxt : g[cur]) {
                dfs(nxt);
                cur_score *= size[nxt];
                size[cur] += size[nxt];
            }
            if(n - size[cur] > 0) cur_score *= (n - size[cur]);
            if(cur_score > max_score) {
                max_score = cur_score;
                ans = 1;
            } else if(cur_score == max_score){
                ans += 1;
            }
        };
        calc_root(0);
        return ans;
    
    }
};