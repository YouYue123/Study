// 66. Plus One [E]
// LeetCode plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int> ans;
        for(int i = n - 1; i >= 0; i --) {
            ans.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
        if(carry != 0) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};