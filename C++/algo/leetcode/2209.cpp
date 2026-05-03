// 2209. Minimum White Tiles After Covering With Carpets [H]
// LeetCode minimum-white-tiles-after-covering-with-carpets

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector memo(n, vector(numCarpets + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int cnt) {
            if(cnt > numCarpets) return INT_MAX / 2;
            if(i >= n) return 0;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            int ans = INT_MAX;
            if(floor[i] == '0') {
                ans = dfs(i + 1, cnt);
            } else {
                ans = min(
                    dfs(i + 1, cnt) + 1,
                    dfs(i + carpetLen, cnt + 1)
                );
            }
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0);
    }
};