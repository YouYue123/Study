#include <bits/stdc++.h>
using namespace std;

// 2300. Successful Pairs of Spells and Potions [M]
// LeetCode successful-pairs-of-spells-and-potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size(), 0);
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i ++) {
            long long s = spells[i];
            int left = 0, right = potions.size() - 1;
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(s * potions[mid] >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if(s * potions[left] >= success) ans[i] = potions.size() - left;
        }
        return ans;
    }
};