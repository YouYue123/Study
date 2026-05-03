#include <bits/stdc++.h>
using namespace std;

// 904. Fruit Into Baskets [M]
// LeetCode fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        unordered_map<int, int> dict;
        int cnt = 0;
        int ans = INT_MIN;
        int curSum = 0;
        while(right < fruits.size()) {
            int f = fruits[right];
            dict[f] += 1;
            curSum += 1;
            if(dict[f] == 1) cnt += 1;
            while(cnt > 2) {
                dict[fruits[left]] -= 1;
                curSum -= 1;
                if(dict[fruits[left]] == 0) cnt -= 1;
                left += 1;
            }
            ans = max(ans, curSum);
            right += 1;
        }
        return ans;
    }
};