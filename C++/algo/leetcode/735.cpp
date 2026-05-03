#include <bits/stdc++.h>
using namespace std;

// 735. Asteroid Collision [M]
// LeetCode asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a : asteroids) {
            bool isEliminated = false;
            while(!st.empty() && a < 0 && st.top() > 0) {
                if(st.top() > abs(a)) {
                    // cout << "eliminate this!" << endl;
                    isEliminated = true;
                    break;
                } else if(st.top() < abs(a)) {
                    // cout << "eliminate prev" << endl;
                    st.pop();
                } else {
                    // cout << "both collision!" << endl;
                    st.pop();
                    isEliminated = true;
                    break;
                }
            }
            if(!isEliminated) st.push(a);
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};