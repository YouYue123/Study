#include <bits/stdc++.h>
using namespace std;

// 773. Sliding Puzzle [H]
// LeetCode sliding-puzzle

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2, n = 3;
        string target = "123450";
        string start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start += to_string(board[i][j]);
            }
        }

        vector<vector<int>> neighbor = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2}
        };

        queue<string> q;
        unordered_map<string, bool> visited;
        q.push(start);
        visited[start] = true;

        int step = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string cur = q.front();
                q.pop();
                if (target == cur) return step;
                int idx = 0;
                for (; cur[idx] != '0'; idx++) ;
                for (int adj : neighbor[idx]) {
                    string new_board = swap(cur, adj, idx);
                    if(visited[new_board]) continue;
                    q.push(new_board);
                    visited[new_board] = true;
                }
            }
            step++;
        }
        return -1;
    }

private:
    // Helper function  swap characters in a string
    string swap(string s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        return s;
    }
};