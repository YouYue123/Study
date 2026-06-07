#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
    public:
        vector<int> maximumMEX(vector<int>& nums) {
            int n = nums.size();
            vector<queue<int>> pos(n + 1);
            for(int i = 0; i < n; i ++) {
                int x = nums[i];
                if(x > n) continue;
                pos[x].push(i);
            }
            vector<int> ans;
            int i = 0;
            while(i < n){
                int mex = 0, start = i, nxt_start = i;
                while(true) {
                    auto& cur = pos[mex];
                    while(!cur.empty() && cur.front() < start) {
                        cur.pop();
                    }
                    if(cur.empty()) break;
                    nxt_start = max(nxt_start, cur.front());
                    mex += 1;
                }
                ans.push_back(mex);
                i = nxt_start + 1;
            }
            return ans;
        }
    };