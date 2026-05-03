// 2033. Minimum Operations to Make a Uni-Value Grid [M]
// LeetCode minimum-operations-to-make-a-uni-value-grid

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> normalised;
        for(auto& row: grid) {
            for(auto item : row) {
                normalised.push_back(item);
            }
        }
        sort(normalised.begin(), normalised.end());
        int n = normalised.size();
        int median = n % 2 == 0 ? 
        normalised[n / 2 - 1] :
        normalised[n / 2];
        // cout << median << endl;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            int item = normalised[i];
            if((item - median) % x != 0) return -1;
            ans += abs(item - median) / x;
        }
        return ans;
    }
};