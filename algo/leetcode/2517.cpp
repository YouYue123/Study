#include <bits/stdc++.h>
using namespace std;

// 2517. Maximum Tastiness of Candy Basket [M]
// LeetCode maximum-tastiness-of-candy-basket

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        auto isValid = [&] (int x) {
            int cnt = 1;
            int pre = price[0];
            for(int i = 1; i < price.size(); i ++) {
                if(price[i] - pre >= x) {
                    pre = price[i];
                    cnt += 1;
                }
            }
            // cout << x << " " << cnt << endl;
            return cnt >= k;
        };
        int left = 0, right = *max_element(price.begin(), price.end());
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                left = mid + 1;                
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};