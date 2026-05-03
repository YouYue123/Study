// 1536. Minimum Swaps to Arrange a Binary Grid [M]
// LeetCode minimum-swaps-to-arrange-a-binary-grid

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> tailZero;
        for(int i = 0; i < m; i ++) {
            int cnt = 0;
            for(int j = n - 1; j >= 0; j --) {
                if(grid[i][j] == 0) cnt += 1;
                else break;
            }
            tailZero.push_back(cnt);
        }
        // for(auto cnt : tailZero) cout << cnt << endl;
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            int required = m - i - 1;
            // cout << "required: " << required << endl;
            if(tailZero[i] >= required) continue;
            bool found = false;
            for(int j = i + 1; j < m; j ++) {
                if(tailZero[j] >= required) {
                    found = true;
                    ans += j - i;
                    while(j > i) {
                        swap(tailZero[j], tailZero[j - 1]);
                        j -= 1;
                    }
                    break;
                }
            }
            if(!found) return -1;
        }
        return ans;
    }
};