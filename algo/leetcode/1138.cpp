#include <bits/stdc++.h>
using namespace std;

// 1138. Alphabet Board Path [M]
// LeetCode alphabet-board-path

class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans = "";
        vector<string> board;
        board.push_back("abcde");
        board.push_back("fghij");
        board.push_back("klmno");
        board.push_back("pqrst");
        board.push_back("uvwxy");
        board.push_back("z");
        int i = 0, j = 0;
        for(char c : target) {
            // cout << "for: " << c << endl;
            while(c != board[i][j]) {
                // cout << board[i][j] << endl;
                if(c > board[i].back()) {
                    if(i == 4) {
                        while(j != 0) {
                            j -= 1;
                            ans += "L";
                        }
                    }
                    i += 1;
                    ans += "D";
                } else if(c < board[i].front()) {
                    i -= 1;
                    ans += "U";
                } else if(c > board[i][j]) {
                    j += 1;
                    ans += "R";
                } else if(c < board[i][j]) {
                    j -= 1;
                    ans += "L";
                }
            }
            ans += "!";
        }
        return ans;
    }
};