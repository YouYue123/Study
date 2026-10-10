#include <bits/stdc++.h>
using namespace std;

// 1792. Maximum Average Pass Ratio [M]
// LeetCode maximum-average-pass-ratio

struct Class {
    double pass;
    long long total;
    bool operator > (const Class& other) {
        return gain() < other.gain();
    }
    double gain () const {
        return (pass + 1) / (total + 1) - ratio();
    }
    double ratio () const {
        return (double) pass / total;
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Class, vector<Class>, greater<>> pq;
        double totalRate = 0.0;
        for(auto& c: classes) pq.emplace(c[0], c[1]);
        while(extraStudents > 0) {
            auto cur = pq.top();
            pq.pop();
            cur.total += 1;
            cur.pass += 1;
            extraStudents -= 1;
            // cout << "push in " << cur.pass << " " << cur.total << endl; 
            pq.emplace(cur.pass, cur.total);
        }
        // cout << pq.size() << endl;
        while(!pq.empty()) {
            auto cur = pq.top();
            // cout << cur.ratio() << endl;
            // (0.25925925925 + 0.5) / 2;
            totalRate += cur.ratio();
            pq.pop();
        }
        // cout << totalRate << endl;
        return totalRate / (double) classes.size();
    }
};