#include <bits/stdc++.h>
using namespace std;

// 2107. Number of Unique Flavors After Sharing K Candies [M]
// LeetCode number-of-unique-flavors-after-sharing-k-candies

class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> dict;
        int totalUniq = 0;
        for(int c : candies) {
            dict[c] += 1;
            if(dict[c] == 1) totalUniq += 1;
        }
        int left = 0, right = 0;
        int ans = 0;
        while(right < candies.size()) {
            dict[candies[right]] -= 1;
            if(dict[candies[right]] == 0) totalUniq -= 1;
            if(right - left + 1 > k) {
                dict[candies[left]] += 1;
                if(dict[candies[left]] == 1) totalUniq += 1;
                left += 1;
            }
            if(right - left + 1 == k) ans = max(ans, totalUniq);
            right += 1;
        }
        return ans;
    }
};