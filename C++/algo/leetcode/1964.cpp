// 1964. Find the Longest Valid Obstacle Course at Each Position [H]
// LeetCode find-the-longest-valid-obstacle-course-at-each-position

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> g;
        for(int i = 0; i < obstacles.size(); i ++) {
            int x = obstacles[i];
            auto idx = upper_bound(g.begin(), g.end(), x) - g.begin();
            ans[i] = idx + 1;
            if(idx == g.size()) {
                g.push_back(x);
            } else {
                g[idx] = x;
            }
        }
        return ans;
    }
};