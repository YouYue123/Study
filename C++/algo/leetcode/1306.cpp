// 1306. Jump Game III [M]
// LeetCode jump-game-iii

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector visited(n, false);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i < 0 || i >= n) return false;
            if(visited[i]) return false;
            if(arr[i] == 0) return true;
            visited[i] = true;
            return dfs(i + arr[i]) || dfs(i - arr[i]);
        };
        return dfs(start);
    }
};