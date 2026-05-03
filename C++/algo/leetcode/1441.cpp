// 1441. Build an Array With Stack Operations [M]
// LeetCode build-an-array-with-stack-operations

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 1, j = 0;
        for(int i = 1; i <= n && j < target.size(); i ++) {
            ans.push_back("Push");
            if(target[j] == i) {
                j += 1;
            } else {
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};