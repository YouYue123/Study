// 3588. Find Maximum Area of a Triangle [M]
// LeetCode find-maximum-area-of-a-triangle

class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        unordered_map<int, vector<int>> x_to_ys;
        unordered_map<int, vector<int>> y_to_xs;
        vector<int> xs;
        vector<int> ys;
        for(auto& c : coords) {
            xs.push_back(c[0]);
            ys.push_back(c[1]);
            x_to_ys[c[0]].push_back(c[1]);
            y_to_xs[c[1]].push_back(c[0]);
        }
        long long ans = -1;
        auto calc = [&] (unordered_map<int, vector<int>>& dict, vector<int>& h) {
            long long minH = *min_element(h.begin(), h.end());
            long long maxH = *max_element(h.begin(), h.end());
            for(auto& [cur, local] : dict) {
                if(local.size() >= 2) {
                    long long minLocal = *min_element(local.begin(), local.end());
                    long long maxLocal = *max_element(local.begin(), local.end());
                    int maxBase = maxLocal - minLocal;
                    long long h = max(maxH - cur, cur - minH);
                    if(h == 0) continue;
                    ans = max(
                        ans,
                        maxBase * h
                    );
                }
            }
        };
        calc(x_to_ys, xs);
        calc(y_to_xs, ys);
        return ans;
    }
};