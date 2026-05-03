#include <bits/stdc++.h>
using namespace std;

// 1061. Lexicographically Smallest Equivalent String [M]
// LeetCode lexicographically-smallest-equivalent-string

struct UF {
    vector<int> parent;
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < parent.size(); i ++) parent[i] = i;
    }
    void union_(int p, int q) {
        int rootP = findRoot(p);
        int rootQ= findRoot(q);
        if(rootP == rootQ) return;
        parent[rootP] = rootQ;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        return  parent[x] = findRoot(parent[x]);
    }
    bool isConnected(int p, int q) {
        return findRoot(p) == findRoot(q);
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UF uf(26);
        for(int i = 0; i < s1.size(); i ++) {
            int c1 = s1[i], c2 = s2[i];
            uf.union_(c1 - 'a', c2 - 'a');
        }
        string ans = "";
        for(int i = 0; i < baseStr.size(); i ++) {
            for(int j = 0; j <= baseStr[i] - 'a'; j ++) {
                if(uf.isConnected(baseStr[i] - 'a', j)) {
                    ans += j + 'a';
                    break;
                }
            }
        }
        return ans;
    }
};