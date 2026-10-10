#include <bits/stdc++.h>
using namespace std;

// 447. Number of Boomerangs [M]
// LeetCode number-of-boomerangs

class Solution {
public:
    long long getDist(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
    int fact(int n){
        return (n==0) || (n==1) ? 1 : n* fact(n-1);
    }
    long long A(int n, int m = 2) {
        return fact(n) / fact(n - m);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // A(n , 2)
        int ans = 0;
        for(int i = 0; i < points.size(); i ++) {
            auto& p1 = points[i];
            // Dist -> cnt
            unordered_map<long long, int> dict;
            for(int j = 0; j < points.size(); j ++) {
                auto& p2 = points[j];
                long long dist = getDist(p1, p2);
                dict[dist] += 1;
            }
            for(auto& p : dict) {
                int cnt = p.second;
                // cout << cnt << endl;
                if(cnt >= 2) ans += A(cnt, 2);
            }
        }
        return ans;
    }
};