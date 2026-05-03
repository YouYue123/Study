// 3529. Count Cells in Overlapping Horizontal and Vertical Substrings [M]
// LeetCode count-cells-in-overlapping-horizontal-and-vertical-substrings

class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        int m = grid.size();
        int n = grid[0].size();
        int N = m * n;
        int L = pattern.size();
        string H;
        H.reserve(N);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                H.push_back(grid[i][j]);
        string V;
        V.reserve(N);
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                V.push_back(grid[i][j]);

        vector<int> pi(L);
        for (int i = 1, j = 0; i < L; ++i) {
            while (j > 0 && pattern[i] != pattern[j])
                j = pi[j - 1];
            if (pattern[i] == pattern[j])
                ++j;
            pi[i] = j;
        }
        auto kmpSearch = [&](const string& T) {
            vector<int> occ;
            for (int i = 0, j = 0; i < (int)T.size(); ++i) {
                while (j > 0 && T[i] != pattern[j])
                    j = pi[j - 1];
                if (T[i] == pattern[j])
                    ++j;
                if (j == L) {
                    occ.push_back(i - L + 1);
                    j = pi[j - 1];
                }
            }
            return occ;
        };
        auto occH = kmpSearch(H);
        auto occV = kmpSearch(V);

        vector<int> diffH(N + 1), diffV(N + 1);
        for (int st : occH) {
            diffH[st] += 1;
            diffH[st + L] -= 1;
        }
        for (int st : occV) {
            diffV[st] += 1;
            diffV[st + L] -= 1;
        }
        vector<char> coverH(N), coverV(N);
        for (int i = 0, cur = 0; i < N; ++i) {
            cur += diffH[i];
            coverH[i] = (cur > 0);
        }
        for (int i = 0, cur = 0; i < N; ++i) {
            cur += diffV[i];
            coverV[i] = (cur > 0);
        }

        int ans = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int hIdx = r * n + c;
                int vIdx = c * m + r;
                if (coverH[hIdx] && coverV[vIdx])
                    ++ans;
            }
        }
        return ans;
    }
};