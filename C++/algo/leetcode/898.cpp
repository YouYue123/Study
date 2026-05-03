// 898. Bitwise ORs of Subarrays [M]
// LeetCode bitwise-ors-of-subarrays

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // vector<int> nums(n);
        unordered_set<int> ans;
        for(int i = 0; i < arr.size(); i ++) {
            int cur = arr[i];
            ans.insert(cur);
            for(int j = i - 1; j >= 0; j --) {
                if((arr[j] | cur) == arr[j]) break;
                arr[j] |= cur;
                ans.insert(arr[j]);
            }
        }
        return ans.size();
    }
};