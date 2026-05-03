#include <bits/stdc++.h>
using namespace std;

// 1931. Painting a Grid With Three Different Colors [H]
// LeetCode painting-a-grid-with-three-different-colors

class Solution {
public:
    int mod = 1e9 + 7;
    
    // Generate all valid colorings for a row of length m
    void generateValidStates(int m, int pos, vector<int>& current, vector<vector<int>>& states) {
        if (pos == m) {
            states.push_back(current);
            return;
        }
        for (int c = 0; c < 3; c++) {
            if (pos == 0 || current[pos-1] != c) {
                current[pos] = c;
                generateValidStates(m, pos + 1, current, states);
            }
        }
    }
    
    // Check if two rows are compatible (no same colors in same column)
    bool isCompatible(const vector<int>& row1, const vector<int>& row2, int m) {
        for (int i = 0; i < m; i++) {
            if (row1[i] == row2[i]) return false;
        }
        return true;
    }
    
    int colorTheGrid(int m, int n) {
        // Generate all valid states for a row
        vector<int> current(m, 0);
        vector<vector<int>> states;
        generateValidStates(m, 0, current, states);
        
        int k = states.size();
        vector<long long> dp(k, 0);
        
        // Initialize for first row: each state is valid
        for (int i = 0; i < k; i++) {
            dp[i] = 1;
        }
        
        // Process each subsequent row
        for (int row = 1; row < n; row++) {
            vector<long long> new_dp(k, 0);
            for (int i = 0; i < k; i++) { // Current row state
                for (int j = 0; j < k; j++) { // Previous row state
                    if (isCompatible(states[i], states[j], m)) {
                        new_dp[i] = (new_dp[i] + dp[j]) % mod;
                    }
                }
            }
            dp = new_dp;
        }
        
        // Sum all valid states for the last row
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans = (ans + dp[i]) % mod;
        }
        
        return ans;
    }
};