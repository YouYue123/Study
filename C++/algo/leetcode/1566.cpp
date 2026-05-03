// 1566. Detect Pattern of Length M Repeated K or More Times [E]
// LeetCode detect-pattern-of-length-m-repeated-k-or-more-times

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int ans = 0;
        for(int i = 0; i < arr.size() - m; i ++) {
            if(arr[i] != arr[i + m]) {
                ans = 0;
            } else{
                ans += 1;
            }
            if (ans == (k - 1) * m) {
                return true;
            }
        }
        return false;
    }
};