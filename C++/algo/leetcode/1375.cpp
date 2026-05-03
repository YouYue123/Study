// 1375. Number of Times Binary String Is Prefix-Aligned [M]
// LeetCode number-of-times-binary-string-is-prefix-aligned

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        // whether there is any zero before the highest one
        int n = flips.size();
        int right = 0;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            right = max(right, flips[i]);
            if(right == i + 1) ans += 1;
        }
        return ans;
    }
};