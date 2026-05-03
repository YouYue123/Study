#include <bits/stdc++.h>
using namespace std;

// 502. IPO [H]
// LeetCode ipo

struct Project {
    int profit;
    int capital;
    bool operator < (const Project& other) const {
        return profit < other.profit;  
    };
    bool operator > (const Project& other) const {
        return profit > other.profit;  
    };
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<Project> projects;
        int n = profits.size();
        for(int i = 0; i < n; i ++) {
            projects.emplace_back(profits[i], capital[i]);
        }
        sort(projects.begin(), projects.end(), [&](const Project& a, const Project& b) {
            return a.capital < b.capital;
        });
        int idx = 0;
        priority_queue<Project, vector<Project>> pq;
        while(idx < n && projects[idx].capital <= w) {
            pq.push(projects[idx]);
            idx += 1;
        }
        for(int i = 0; i < k; i ++) {
            if(pq.empty()) break;
            w += pq.top().profit;
            pq.pop();
            while(idx < n && projects[idx].capital <= w) {
                pq.push(projects[idx]);
                idx += 1;
            }
        }
        return w;
    }
};