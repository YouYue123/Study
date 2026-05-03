#include <bits/stdc++.h>
using namespace std;

// 630. Course Schedule III [H]
// LeetCode course-schedule-iii

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [&] (auto& a, auto& b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        // store the selected courses duration
        priority_queue<int> pq;
        int day = 0;
        for(auto& c : courses) {
            // cout << c[0] << " " << c[1] << endl;
            int duration = c[0], lastDay = c[1];
            if(day + duration <= lastDay) {
                pq.push(duration);
                day += duration;
                // cout << pq.top() << endl;
            } else if(!pq.empty() && pq.top() > duration) {
                // cout << pq.top () << endl;
                day = day - pq.top() + duration;
                pq.pop();
                pq.push(duration);
            }
        }
        return pq.size();
    }
};