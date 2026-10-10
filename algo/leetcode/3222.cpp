#include <bits/stdc++.h>
using namespace std;

// 3222. Find the Winning Player in Coin Game [E]
// LeetCode find-the-winning-player-in-coin-game

class Solution {
public:
    string winningPlayer(int x, int y) {
        int yCount = y / 4;
        int minCount = min(x, yCount);
        return minCount % 2 == 0 ? "Bob":"Alice";
    }
};