// 2242. Maximum Score of a Node Sequence [H]
// LeetCode maximum-score-of-a-node-sequence

class Solution {
public:
    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(scores.size());
        int n = scores.size();
        for(auto& e : edges) {
            int x = e[0],  y = e[1];
            graph[x].push_back({ scores[y], y });
            graph[y].push_back({ scores[x], x });
        }
        int ans = -1;
        for(auto& vs: graph) {
            if(vs.size() > 5) {
                nth_element(vs.begin(), vs.begin() + 5, vs.end(), greater<>());
                vs.resize(5);
            }
        }
        for(auto e : edges) {
            int x = e[0], y = e[1];
            for(auto &[score_a, a] : graph[x]) {
                for(auto &[score_b, b] : graph[y]) {
                    if(a != y && b != x && a != b) {
                        ans = max(ans, score_a + scores[x] + scores[y] + score_b);
                    }
                }
            }
        }
        return ans;
    }
};