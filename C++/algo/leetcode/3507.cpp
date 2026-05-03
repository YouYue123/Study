#include <bits/stdc++.h>
using namespace std;

// 3507. Minimum Pair Removal to Sort Array I [E]
// LeetCode minimum-pair-removal-to-sort-array-i

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> curNums(nums.begin(), nums.end());
        int ans = 0;
        while(true) {
            int n = curNums.size();
            bool isValid = true;
            int curMin = INF;
            int minIdx = -1;
            for(int i = 0; i < curNums.size() - 1; i ++) {
                if(curNums[i] > curNums[i + 1]) {
                    isValid = false;
                }
                int sum = curNums[i] + curNums[i + 1];
                if(sum < curMin) {
                    curMin = sum;
                    minIdx = i;
                }
            }
            if(isValid) break;
            ans += 1;
            vector<int> nxtNums;
            int i = 0;
            while(i < n) {
                 if(i == minIdx) {
                    nxtNums.push_back(curMin);
                    i += 2;
                 } else {
                    nxtNums.push_back(curNums[i]);
                    i += 1;
                 }
            }
            curNums = nxtNums;
            // for(int item : curNums) cout << item << " ";
            // cout << endl;
        }
        return ans;
    }
};