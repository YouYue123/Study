#include <bits/stdc++.h>
using namespace std;

// 737. Sentence Similarity II [M]
// LeetCode sentence-similarity-ii

struct UF {
    vector<int> parent;
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    void union_(int p, int q) {
        int rootP = findRoot(p);
        int rootQ = findRoot(q);
        if(rootP == rootQ) return;
        parent[rootP] = rootQ;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }
    bool connected(int i, int j) {
        return findRoot(i) == findRoot(j);
    }
};
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;
        unordered_map<string, int> dict;
        int index = 0;
        for(string& s: sentence1) {
            if(!dict.contains(s)) {
                dict[s] = index;
                index += 1;
            }
        }
        for(string& s: sentence2) {
            if(!dict.contains(s)) {
                dict[s] = index;
                index += 1;
            }
        }
         for(auto& p : similarPairs) {
            string from = p[0];
            string to = p[1];
            if(!dict.contains(from)) {
                dict[from] = index;
                index += 1;
            }
            if(!dict.contains(to)) {
                dict[to] = index;
                index += 1;
            }
        }
        UF uf(index);
        for(auto& p : similarPairs) {
            string from = p[0];
            string to = p[1];
            uf.union_(dict[from], dict[to]);
        }
        for(int i = 0; i < sentence1.size(); i ++) {
            int s1Index = dict[sentence1[i]];
            int s2Index = dict[sentence2[i]];
            if(s1Index == s2Index || uf.connected(s1Index, s2Index)) continue;
            else return false;
        }
        return true;
    }
};