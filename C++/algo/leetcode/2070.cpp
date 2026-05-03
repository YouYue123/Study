// 2070. Most Beautiful Item for Each Query [M]
// LeetCode most-beautiful-item-for-each-query

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> maxSoFar(items.size(), 0);
        int maxBeauty = INT_MIN;
        for(int i = 0; i < items.size(); i ++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            maxSoFar[i] = maxBeauty;
        }
        vector<int> ans;
        for(int q : queries) {
            int left = 0, right = items.size();
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(items[mid][0] >= q + 1) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if(left == 0) ans.push_back(0);
            else {
                ans.push_back(maxSoFar[left - 1]);
            }
        }
        return ans;
    }
};