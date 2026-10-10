#include <bits/stdc++.h>
using namespace std;

// 1652. Defuse the Bomb [E]
// LeetCode defuse-the-bomb

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(), 0);
        if(k == 0) return ans;
        int left = 1, right = k, sum = 0;
        if(k < 0) {
            left = code.size() - abs(k);
            right = code.size() - 1;
        }
        for(int i = left; i <= right; i ++) sum += code[i];
        for(int i = 0; i < code.size(); i ++) {
            ans[i] = sum;
            sum -= code[left % code.size()];
            sum += code[(right + 1) % code.size()];
            left += 1;
            right += 1;
        }
        return ans;
    }
};