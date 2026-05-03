#include <bits/stdc++.h>
using namespace std;

// 2106. Maximum Fruits Harvested After at Most K Steps [H]
// LeetCode maximum-fruits-harvested-after-at-most-k-steps

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // 2a + b = k or 2b + a = k
        unordered_map<int, int> dict;
        for(auto& fruit : fruits) dict[fruit[0]] = fruit[1];
        int left = startPos, right = startPos;
        int sum = 0;
        int ans = 0;
        while(right < startPos + k + 1) {
            sum += dict[right];
            // cout << left << " "  << right << " " << sum << endl;
            right += 1;
            ans = max(ans, sum);
        }
        right -= 1;
        // cout << "move left "  << sum << endl;
        while(right >= startPos) {
            sum += dict[left - 1];
            sum -= dict[right];
            sum -= dict[right - 1];
            left -= 1;
            right -= 2;
            // cout << left << " " << right << " " << sum << endl;
            ans = max(ans, sum);
        }
        left = startPos, right = startPos;
        sum = 0;
        while(left >= startPos - k) {
            sum += dict[left];
            // cout << left << " "  << right << " " << sum << endl;
            left -= 1;
            ans = max(ans, sum);
        }
        left += 1;
        // cout << "move right " << sum << endl;
        while(left <= startPos) {
            sum += dict[right + 1];
            sum -= dict[left];
            sum -= dict[left + 1];
            left += 2;
            right += 1;
            // cout << left << " " << right << " " << sum << endl;
            ans = max(ans, sum);
        }
        return ans;
    }
};