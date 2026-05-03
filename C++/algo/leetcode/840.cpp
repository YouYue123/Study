// 840. Magic Squares In Grid [M]
// LeetCode magic-squares-in-grid

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        auto isValid = [&] (int i, int j) -> bool {
            int full = ((1 << 10) - 1) ^ 1;
            int state = 0;
            int rowSum[3] = {0};
            int colSum[3] = {0};
            int diagnalSum[2] = {0};
            for(int x = i; x < m && x < i + 3; x ++) {
                int rowIdx = x - i;
                for(int y = j; y < n && y < j + 3; y ++) {
                    int colIdx = y - j;
                    rowSum[rowIdx] += grid[x][y];
                    colSum[colIdx] += grid[x][y];
                    if(rowIdx == colIdx) {
                        diagnalSum[0] += grid[x][y];
                    }
                    if(rowIdx == abs(2 - colIdx)) {
                        diagnalSum[1] += grid[x][y];
                    }
                    state = state | (1 << grid[x][y]);
                }
            }
            if(full != state) return false;
            for(int sum : rowSum) {
                // cout << sum << endl 
                if(sum != 15) return false;
            }
            for(int sum : colSum) {
                if(sum != 15) return false;
            }
            for(int sum : diagnalSum) {
                // cout << "diagnalSum: " << sum << endl;
                if(sum != 15) return false;
            }
            // cout << endl;
            // cout << "curState: " << state << endl;
            // cout << cnt << endl;
            // cout << state << " " << full << endl;
            return true;
        };
        int ans = 0;
        for(int i = 0; i < m - 2; i ++) {
            for(int j = 0; j < n - 2; j ++) {
                if(isValid(i, j)) {
                    ans += 1;
                }
            }
        } 
        return ans;
    }
};