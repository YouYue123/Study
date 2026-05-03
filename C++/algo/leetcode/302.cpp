// 302. Smallest Rectangle Enclosing Black Pixels [H]
// LeetCode smallest-rectangle-enclosing-black-pixels

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int minX = INT_MAX, maxX= INT_MIN;
        int minY = INT_MAX, maxY = INT_MIN;
        unordered_map<int, unordered_map<int, bool>> visited;
        function<void(int i, int j)> dfs = [&] (int i, int j) {
            if(i < 0 || i == m) return;
            if(j < 0 || j == n) return;
            if(image[i][j] == '0') return; 
            if(visited[i][j]) return;
            visited[i][j] = true;
            minX = min(minX, i);
            maxX = max(maxX, i);
            minY = min(minY, j);
            maxY = max(maxY, j); 
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };
        for(int i = 0; i < m ; i ++) {
            for(int j = 0; j < n ; j ++) {
                if(image[i][j] == '1') {
                    dfs(i, j);
                } 
            }
        }
        // cout << "minX: " << minX << "maxX: " << maxX << endl;
        // cout << "minY: " << minY << "maxY: " << maxY << endl;
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};