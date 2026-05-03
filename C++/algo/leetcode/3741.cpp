// 3741. Minimum Distance Between Three Equal Elements II [M]
// LeetCode minimum-distance-between-three-equal-elements-ii

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, stack<int>> dict;
        for(int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            dict[num].push(i);
        }
        int ans = INT_MAX;
        for(auto& item : dict) {
            // cout << item.first << " " << item.second.size()  << endl;
            if(item.second.size() >= 3) {
                auto& st = item.second;
                int i = INT_MAX, j = INT_MAX, k = INT_MAX;
                while(!st.empty()) {
                    i = j;
                    j = k;
                    k = st.top();
                    st.pop();
                    if(i != INT_MAX) {
                        int dist = abs(i - j) + abs(j - k) + abs(k - i);
                        ans = min(ans, dist);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};