#include <bits/stdc++.h>
using namespace std;
struct UF
{
    vector<int> parent;
    int n;
    UF(int size) : n(size), parent(size)
    {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int findRoot(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findRoot(parent[x]);
    }
    void unite(int x, int y)
    {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY)
        {
            parent[rootY] = rootX;
        }
    }
    bool connected(int x, int y)
    {
        return findRoot(x) == findRoot(y);
    }
    int size()
    {
        return n;
    }
};