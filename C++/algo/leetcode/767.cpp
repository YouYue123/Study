#include <bits/stdc++.h>
using namespace std;

// 767. Reorganize String [M]
// LeetCode reorganize-string

struct Node {
    char c;
    int freq;
    bool operator < (const Node& other) const {
        return freq < other.freq;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;
        priority_queue<Node> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (freq[i] > (n + 1) / 2) return "";
                pq.emplace(i + 'a', freq[i]);
            }
        }
        string ans = "";
        while (pq.size() >= 2) {
            Node node1 = pq.top(); 
            pq.pop();
            Node node2 = pq.top(); 
            pq.pop();
            ans += node1.c;
            ans += node2.c;
            if (--node1.freq > 0) pq.push(node1);
            if (--node2.freq > 0) pq.push(node2);
        }
        if (!pq.empty()) ans += pq.top().c;
        return ans;
    }
};