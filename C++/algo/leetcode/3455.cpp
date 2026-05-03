#include <bits/stdc++.h>
using namespace std;

// 3455. Shortest Matching Substring [H]
// LeetCode shortest-matching-substring

class Solution {
public:
    vector<int> calcPi(const string& p) {
        vector<int> pi(p.size());
        int match = 0;
        for(int i = 1; i < p.size(); i ++) {
            char v = p[i];
            while(match > 0 && p[match] != v) {
                match = pi[match - 1];
            }
            if(p[match] == v) {
                match ++;
            }
            pi[i] = match;
        }
        return pi;
    }
    vector<int> kmp(const string& s, const string& p) {
        if(p.empty()) {
            vector<int> pos(s.size() + 1);
            ranges::iota(pos, 0);
            return pos;
        }
        vector<int> pi = calcPi(p);
        vector<int> pos;
        int match = 0;
        for(int i =0; i < s.size(); i ++) {
            char v = s[i];
            while(match > 0 && p[match] != v) match = pi[match - 1];
            if(p[match] == v) match += 1;
            if(match == p.size()) {
                pos.push_back(i - p.size() + 1);
                match = pi[match - 1];
            }
        }
        return pos;
    } 
    int shortestMatchingSubstring(string s, string p) {
        int star1 = p.find('*');
        int star2 = p.rfind('*');
        vector<int> pos1 = kmp(s, p.substr(0, star1));
        vector<int> pos2 = kmp(s, p.substr(star1 + 1, star2 - star1 - 1));
        vector<int> pos3 = kmp(s, p.substr(star2 + 1));
        int len1 = star1;
        int len2 = star2 - star1 - 1;
        int len3 = p.size() - star2 - 1;
        int ans = INT_MAX;
        int i =0, k = 0;
        for(int j : pos2) {
            while(k < pos3.size() && pos3[k] < j + len2) k += 1;
            if(k == pos3. size()) break;
            while(i < pos1.size() && pos1[i] <= j - len1) i += 1;
            if(i > 0) ans = min(ans, pos3[k] + len3 - pos1[i - 1]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};