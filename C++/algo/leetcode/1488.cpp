#include <bits/stdc++.h>
using namespace std;

// 1488. Avoid Flood in The City [M]
// LeetCode avoid-flood-in-the-city

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;
        unordered_map<int, int> fw;
        set<int> dry;
        bool flood = false;
        for(int i = 0; i < rains.size(); i ++) {
            int r = rains[i];
            if(r > 0) {
                if(fw.contains(r)) {
                    int lastIndex = fw[r];
                    auto it = dry.upper_bound(lastIndex);
                    if(it == dry.end()) {
                        flood = true;
                        break;
                    } else {
                        ans[(*it)] = r;
                        dry.erase(it);
                        fw[r] = i;
                    }
                } else fw[r] = i;
                ans.push_back(-1);
            } else {
                ans.push_back(1);
                dry.insert(i);
            }
        }
        vector<int> empty;
        return flood ? empty : ans;
    }
};