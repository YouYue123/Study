// 2011. Final Value of Variable After Performing Operations [E]
// LeetCode final-value-of-variable-after-performing-operations

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(string& s : operations) {
            if(s.contains('-')) ans -= 1;
            else ans += 1;
        }
        return ans;
    }
};