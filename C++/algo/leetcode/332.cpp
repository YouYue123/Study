// 332. Reconstruct Itinerary [H]
// LeetCode reconstruct-itinerary

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<>>> g;
        for(auto& t : tickets) {
            g[t[0]].push(t[1]);
        }
        vector<string> ans;
        auto dfs = [&] (this auto&& dfs, string cur) -> void {
            while(!g[cur].empty()) {
                auto nxt = g[cur].top();
                g[cur].pop();
                dfs(nxt);
            }
            ans.push_back(cur);
        };
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};