#include <bits/stdc++.h>
using namespace std;

// 427. Construct Quad Tree [M]
// LeetCode construct-quad-tree

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool sameVal(vector<vector<int>>& grid, int i, int j, int length) {
        for(int x = i; x < i + length; x ++) {
            for (int y = j; y < j + length; y ++) {
                if(grid[x][y] != grid[i][j]) return false;
            }
        }
        return true;
    }
    Node* dfs(vector<vector<int>>& grid, int i, int j, int length) {
        if(sameVal(grid, i, j, length)) {
            return new Node(grid[i][j], true);
        } else {
            Node* root = new Node(0, false);
            root->topLeft = dfs(grid, i, j, length / 2);
            root->topRight = dfs(grid, i, j + length / 2, length / 2);
            root->bottomLeft = dfs(grid, i + length / 2, j, length / 2);
            root->bottomRight = dfs(grid, i + length / 2, j + length / 2, length / 2);
            return root;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }
};