// 1895. Largest Magic Square [M]
// LeetCode largest-magic-square

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector rowPresum(m, vector<int>(n + 1, 0));
        vector colPresum(n, vector<int>(m + 1, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                rowPresum[i][j + 1] = grid[i][j] + rowPresum[i][j];
                colPresum[j][i + 1] = grid[i][j] + colPresum[j][i];
            }
        }
        // cout << "here" << endl;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int diagnalSum = 0;
                int antiDiag = 0;
                int ni = i, nj = j;
                // cout << i << " " << j << endl;
                while(ni < m && nj < n) {
                    diagnalSum += grid[ni][nj];
                    ni += 1;
                    nj += 1;
                    bool isValid = true;
                    int antiDiagSum = 0;
                    for (int k = 0; k < ni - i; k++) {
                        antiDiagSum += grid[i + k][nj - 1 - k];
                    }
                    if (antiDiagSum != diagnalSum) isValid = false;
                    for(int k = i; k < ni; k ++) {
                        int rowSum = rowPresum[k][nj] - rowPresum[k][j];
                        if(rowSum != diagnalSum) {
                            isValid = false;
                            break;
                        }
                    }
                    for(int k = j; k < nj; k ++) {
                        int colSum = colPresum[k][ni] - colPresum[k][i];
                        if(colSum != diagnalSum) {
                            isValid = false;
                            break;
                        }
                    }
                    if(isValid) ans = max(ans, ni - i);
                }
            }
        }
        return ans;
    }
};