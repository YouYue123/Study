#include <bits/stdc++.h>
using namespace std;

// 2211. Count Collisions on a Road [M]
// LeetCode count-collisions-on-a-road

class Solution {
public:
    int countCollisions(string directions) {
        stack<pair<char, int>> st;
        int ans = 0;
        for(char c : directions) {
            if(c == 'L') {
                if(!st.empty()) {
                    if(st.top().first == 'L') {
                        st.emplace(c, 1);
                    } else {
                        ans += (st.top().first == 'R' ? 1 + st.top().second : 1);
                        st.emplace('S', 1);
                    }
                    continue;
                }
            } else if(c == 'S') {
                if(!st.empty() && st.top().first == 'R') {
                    ans += st.top().second;
                }
                st.emplace(c, 1);
            } else if(c == 'R') {
                if(!st.empty() && st.top().first == 'R') {
                    st.top().second += 1;
                } else {
                    st.emplace(c, 1);
                }
            }
        }
        return ans;
    }
};