#include <bits/stdc++.h>

using namespace std;

struct KMP
{
    // LSP -> longest proper prefix
    vector<int> get_lsp(const string &p) {
        vector<int> lsp(p.size());
        for (int i = 1, match = 0; i < p.size(); i++) {
            while (match > 0 && p[match] != p[i])  match = lsp[match - 1];
            if (p[match] == p[i]) match++;
            lsp[i] = match;
        }
        return lsp;
    }
    vector<int> kmp(const string &s, const string &p) {
        int n = s.size(), m = p.size();
        vector<int> lsp = get_lsp(p);
        vector<int> pos;
        for (int i = 0, match = 0; i < n; i++) {
            char v = s[i];
            while (match > 0 && p[match] != v) match = lsp[match - 1]; 
            if (p[match] == v) match += 1;
            if (match == m) {
                pos.push_back(i - m + 1);
                match = lsp[match - 1];
            }
        }
        return pos;
    }
};