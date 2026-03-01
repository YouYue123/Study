#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class CandyCrush {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int R = board.size();
        if (R == 0) return board;
        int C = board[0].size();
        bool todo = true;

        while (todo) {
            todo = false;

            // --- 1. 双指针水平标记 ---
            for (int r = 0; r < R; ++r) {
                int left = 0;
                while (left < C) {
                    int right = left;
                    while (right < C && abs(board[r][right]) == abs(board[r][left])) {
                        right++;
                    }
                    // 找到长度 >= 3 的区间 [left, right-1]
                    if (abs(board[r][left]) != 0 && right - left >= 3) {
                        todo = true;
                        for (int i = left; i < right; ++i) {
                            board[r][i] = -abs(board[r][i]); // 标记为负数
                        }
                    }
                    left = right;
                }
            }

            // --- 2. 双指针垂直标记 ---
            for (int c = 0; c < C; ++c) {
                int top = 0;
                while (top < R) {
                    int bottom = top;
                    while (bottom < R && abs(board[bottom][c]) == abs(board[top][c])) {
                        bottom++;
                    }
                    // 找到长度 >= 3 的区间 [top, bottom-1]
                    if (abs(board[top][c]) != 0 && bottom - top >= 3) {
                        todo = true;
                        for (int i = top; i < bottom; ++i) {
                            board[i][c] = -abs(board[i][c]); // 标记为负数
                        }
                    }
                    top = bottom;
                }
            }

            // --- 3. 双指针重力掉落 (只处理 todo 为 true 的情况) ---
            if (todo) {
                for (int c = 0; c < C; ++c) {
                    int writeIdx = R - 1;
                    // 从底向上扫描，只保留正数（即未标记消除的块）
                    for (int r = R - 1; r >= 0; --r) {
                        if (board[r][c] > 0) {
                            board[writeIdx--][c] = board[r][c];
                        }
                    }
                    // 上方空位补 0
                    while (writeIdx >= 0) {
                        board[writeIdx--][c] = 0;
                    }
                }
            }
        }
        return board;
    }
};