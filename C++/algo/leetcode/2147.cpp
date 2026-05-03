#include <bits/stdc++.h>
using namespace std;

// 2147. Number of Ways to Divide a Long Corridor [H]
// LeetCode number-of-ways-to-divide-a-long-corridor

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> seatPositions;        
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') seatPositions.push_back(i);
        }
        int m = seatPositions.size();
        if (m == 0 || m % 2 != 0) return 0;
        long long ans = 1;
        for (int i = 2; i < m; i += 2) {
            int plantsBetween = seatPositions[i] - seatPositions[i - 1];
            ans = (ans * plantsBetween) % MOD;
        }
        
        return ans;
    }
};