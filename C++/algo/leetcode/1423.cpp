#include <bits/stdc++.h>
using namespace std;

// 1423. Maximum Points You Can Obtain from Cards [M]
// LeetCode maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0, right = 0;
        int sum = 0;
        int n = cardPoints.size();
        int ans = 0;
        while(left < n) {
            sum += cardPoints[right % n];
            if(right - left + 1 > k) {
                sum -= cardPoints[left];
                left += 1;
            }
            if(right - left + 1 == k) {
                // cout << left << " " << right << " " << sum << endl;
                if(left == 0 || right >= n - 1) ans = max(ans, sum);
            }
            right += 1;
        }
        return ans;
    }
};