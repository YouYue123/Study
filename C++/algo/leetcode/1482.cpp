#include <bits/stdc++.h>
using namespace std;

// 1482. Minimum Number of Days to Make m Bouquets [M]
// LeetCode minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int left = 0, right = *max_element(bloomDay.begin(), bloomDay.end()) + 1;
        auto isValid = [&] (int x) {
            int consecCnt = 0;
            int cnt = 0;
            for(int i = 0; i < n; i ++) {
                if(bloomDay[i] <= x) {
                    consecCnt += 1;
                    if(consecCnt == k) {
                        consecCnt = 0;
                        cnt += 1;   
                    }
                } else {
                    consecCnt = 0;
                }
            }
            return cnt >= m;
        };
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return isValid(left + 1) ? left + 1 : -1;
    }
};