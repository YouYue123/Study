#include <bits/stdc++.h>
using namespace std;

// 358. Rearrange String k Distance Apart [H]
// LeetCode rearrange-string-k-distance-apart

struct Item {
    char val;
    int freq;
    bool operator <(const Item& other) const {
        if(freq == other.freq) return val < other.val;
        return freq < other.freq;
    }
};
class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k == 0) return s;
        int freq[26];
        for(char c: s) {
            freq[c - 'a'] += 1;
        }
        priority_queue<Item> pq;
        for(int i = 0; i < 26; i ++) {
            if(freq[i] != 0) {
                pq.emplace(i + 'a', freq[i]);
            }
        }
        string ans = "";
        while(!pq.empty()) {
            vector<Item> waitList;
            for(int i = 0; i < k; i ++) {
                if(!pq.empty()) {
                    auto cur = pq.top();
                    pq.pop();
                    cur.freq -= 1;
                    ans += cur.val;
                    if(cur.freq != 0) waitList.push_back(cur);
                } else {
                    if(waitList.empty()) break;
                    return "";
                }
            }
            for(auto& item : waitList) pq.push(item);
        }
        return ans;
    }
};