#include <bits/stdc++.h>
using namespace std;

// 2528. Maximize the Minimum Powered City [H]
// LeetCode maximize-the-minimum-powered-city

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }
        auto isValid = [&] (long long x) -> bool {
            vector<long long> diff = cnt;
            long long remain = k;
            long long curPower = 0;
            for(int i = 0 ; i < n ; i ++) {
                curPower += diff[i];
                if(curPower < x) {
                    long long add = abs(curPower - x);
                    if(remain < add) return false;
                    long long end = min(n, i + 2 * r + 1);
                    diff[end] -= add;
                    remain -= add;
                    curPower += add;
                }
            }
            return true;
        };
        long long left = 0;
        long long right = 1e18; 
        while(left < right) {
            long long mid = left + (right - left) / 2;
            // cout << left << " " <<  mid << " " << right << endl;
            if(isValid(mid)) {
                // cout << "valid" << endl;
                left = mid + 1;
            } else {
                // cout << "not valid" << endl;
                right = mid;
            }
        }
        return left - 1;
    }
};