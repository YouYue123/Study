// 3531. Count Covered Buildings [M]
// LeetCode count-covered-buildings

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, unordered_set<int>> x_to_y;
        unordered_map<int, unordered_set<int>> y_to_x;
        for(auto& b : buildings) {
            x_to_y[b[0]].insert(b[1]);
            y_to_x[b[1]].insert(b[0]);
        }
        unordered_map<int, pair<int, int>> x_to_y_min_max;
        for (const auto& [x, ys] : x_to_y) {
            int min_y = *min_element(ys.begin(), ys.end());
            int max_y = *max_element(ys.begin(), ys.end());
            x_to_y_min_max[x] = {min_y, max_y};
        }

        unordered_map<int, pair<int, int>> y_to_x_min_max;
        for (const auto& [y, xs] : y_to_x) {
            int min_x = *min_element(xs.begin(), xs.end());
            int max_x = *max_element(xs.begin(), xs.end());
            y_to_x_min_max[y] = {min_x, max_x};
        }
        int ans = 0;
        for(auto& b : buildings) {
            int x = b[0], y = b[1];
            const auto& [min_x, max_x] = y_to_x_min_max[y];
            bool has_left = min_x < x;
            bool has_right = max_x > x;
            const auto& [min_y, max_y] = x_to_y_min_max[x];
            bool has_above = min_y < y;
            bool has_below = max_y > y;
            if (has_left && has_right && has_above && has_below) {
                ans += 1;
            }
        }
        return ans;
    }
};