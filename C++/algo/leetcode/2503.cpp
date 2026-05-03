#include <bits/stdc++.h>
using namespace std;

// 2503. Maximum Number of Points From Grid Queries [H]
// LeetCode maximum-number-of-points-from-grid-queries

class Cell {
public:
    int row;
    int col;
    int val;
    Cell(int r, int c, int v): row(r), col(c), val(v) {}
};

class Query {
public:
    int index;
    int val;
    Query(int i, int v): index(i), val(v) {}
};

bool operator < (const Cell& a, const Cell& b) { return a.val < b.val; };

bool operator < (const Query& a, const Query& b) { return a.val < b. val; };

class UF {
vector<int> parent;
vector<int> size;
public:
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.assign(n, 1);
    }
    void union_ (int p, int q) {
        // cout << "union: " << endl;
        // cout << "p :" << p << " q: " << q << endl;
        int rootP = findRoot(p);
        int rootQ= findRoot(q);
        if(rootP == rootQ) return;
        // Union by size: attach smaller tree to larger tree
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
        return;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        int root = findRoot(parent[x]);
        parent[x] = root;
        return root;
    }

    int getSize(int x) {
        return size[findRoot(x)];
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        int totalCells = rowCount * colCount;
        vector<Query> sortedQueires;
        for(int i = 0; i < queries.size(); i ++) {
            sortedQueires.push_back(Query(i, queries[i]));
        }
        sort(sortedQueires.begin(), sortedQueires.end());
        vector<Cell> sortedCells;
        for(int i = 0; i < rowCount; i ++) {
            for(int j = 0; j < colCount; j ++) {
                sortedCells.push_back(Cell(i, j, grid[i][j]));
            }
        }
        sort(sortedCells.begin(), sortedCells.end());
        auto uf = UF(totalCells);
        vector<int> ans(queries.size());
        int cellIndex = 0;
        for(auto& q : sortedQueires) {
            // cout << "For q: " << q.val << endl;
            // Process cells whoes values are smaller then q val
            while(cellIndex < totalCells && sortedCells[cellIndex].val < q.val) {
                int row = sortedCells[cellIndex].row;
                int col = sortedCells[cellIndex].col;
                int cellId = row * colCount + col;
                // cout << "row: " << row << "col:" << col << endl;
                tryUnion(grid, uf, row + 1, col, q.val , colCount,cellId);
                tryUnion(grid, uf, row - 1, col, q.val , colCount,cellId);
                tryUnion(grid, uf, row, col + 1, q.val , colCount,cellId);
                tryUnion(grid, uf, row, col - 1, q.val , colCount,cellId);
                cellIndex += 1;
            }
            ans[q.index] = q.val > grid[0][0] ? uf.getSize(0) : 0;
        }
        return ans;
    }

    void tryUnion (vector<vector<int>>& grid, UF& uf, int i, int j, int q, int colCount, int cellId) {
        if(i < 0 || i >= grid.size()) return;
        if(j < 0 || j >= grid[i].size()) return;
        if(grid[i][j] >= q) return ;
        uf.union_(cellId, i * colCount + j );
        return;
    }

};