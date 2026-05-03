// 1105. Filling Bookcase Shelves [M]
// LeetCode filling-bookcase-shelves

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int curMaxH = 0;
            int curW = 0;
            int ans = INT_MAX;
            for(int j = i; j < n; j ++) {
                curW += books[j][0];
                if(curW > shelfWidth) break;
                curMaxH = max(curMaxH, books[j][1]);
                ans = min(ans, curMaxH + dfs(j + 1));
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};