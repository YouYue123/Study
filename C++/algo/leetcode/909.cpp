#include <bits/stdc++.h>
using namespace std;

// 909. Snakes and Ladders [M]
// LeetCode snakes-and-ladders

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // 获取棋盘大小（n x n）
        int n = board.size();
        
        // 第一步：调整棋盘方向，方便计算坐标
        // 原始棋盘是从左下角开始编号，我们需要反转行顺序
        reverse(board.begin(), board.end());
        
        // 处理蛇形排列：奇数行需要反转
        for(int i = 0; i < n; i++) {
            if(i % 2 == 1) {
                reverse(board[i].begin(), board[i].end());
            }
        }
        // 现在棋盘变成从左到右、从下到上编号，方便计算坐标
        
        // BFS初始化
        queue<int> q;  // BFS队列
        vector<int> dist(n * n + 1, -1);  // 记录每个位置的最短步数，初始为-1表示未访问
        q.push(1);     // 从起点1开始
        dist[1] = 0;   // 起点步数为0
        
        // BFS主循环
        while(!q.empty()) {
            auto cur = q.front();  // 当前所在位置
            q.pop();
            
            // 如果到达终点，直接返回当前步数
            if(cur == n * n) return dist[cur];
            
            // 模拟掷骰子1-6
            for(int i = 1; i <= 6; i++) {
                int next = cur + i;  // 可能到达的位置
                
                // 超出棋盘范围则跳过
                if(next > n * n)  continue;
                
                // 计算在棋盘上的行列坐标
                // -1是因为棋盘编号从1开始，而数组索引从0开始
                int row = (next - 1) / n;  // 行号
                int col = (next - 1) % n;  // 列号
                
                // 判断是否是蛇或梯子
                // 如果是-1表示普通格子，否则是蛇或梯子
                int dest = board[row][col] == -1 ? next : board[row][col];
                
                // 如果目标位置未被访问过
                if(dist[dest] == -1) {
                    dist[dest] = dist[cur] + 1;  // 更新步数
                    q.push(dest);                // 加入队列
                }
            }
        }
        
        // 如果无法到达终点，返回终点位置的步数（可能是-1）
        return dist[n * n];
    }
};