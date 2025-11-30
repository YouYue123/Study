#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/dsu/

/**
 * Union-Find (Disjoint Set Union) data structure
 * Supports efficient union and find operations for disjoint sets
 * Uses path compression optimization for O(α(n)) amortized time complexity
 */
struct UF
{
    vector<int> parent;  // parent[i] stores the parent of element i, or i itself if it's a root
    int n;                // Total number of elements

    /**
     * Constructor: Initialize n disjoint sets, each containing one element
     * @param size Number of elements (0 to size-1)
     */
    UF(int size) : n(size), parent(size)
    {
        // Initially, each element is its own parent (each element is a root)
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    /**
     * Find the root of the set containing element x
     * Uses path compression: makes all nodes on the path point directly to the root
     * @param x The element to find the root for
     * @return The root of the set containing x
     */
    int findRoot(int x)
    {
        if (parent[x] == x)
            return x;  // x is the root
        // Path compression: set parent[x] to root and return root
        return parent[x] = findRoot(parent[x]);
    }

    /**
     * Union two sets containing elements x and y
     * Merges the sets by making rootY point to rootX
     * @param x First element
     * @param y Second element
     */
    void unite(int x, int y)
    {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY)
        {
            // Merge: make rootY's parent point to rootX
            parent[rootY] = rootX;
        }
    }

    /**
     * Check if two elements are in the same set
     * @param x First element
     * @param y Second element
     * @return true if x and y are in the same set, false otherwise
     */
    bool connected(int x, int y)
    {
        return findRoot(x) == findRoot(y);
    }

    /**
     * Get the total number of elements
     * @return The number of elements in the Union-Find structure
     */
    int size()
    {
        return n;
    }
};