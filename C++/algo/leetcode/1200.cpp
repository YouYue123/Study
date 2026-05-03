// 1200. Minimum Absolute Difference [E]
// LeetCode minimum-absolute-difference

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int curMin = INF;
        for(int i = 0; i < n - 1; i ++) {
            int curDiff =  arr[i + 1] - arr[i];
            if(curMin > curDiff) {
                curMin = curDiff;
                ans.clear();
            }
            if(curMin == curDiff) ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
};