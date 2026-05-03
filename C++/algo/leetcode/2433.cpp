// 2433. Find The Original Array of Prefix Xor [M]
// LeetCode find-the-original-array-of-prefix-xor

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
       int n = pref.size();
        vector<int> ans;
        ans.push_back(pref[0]);
        for(int i = 1; i < n; i ++) {
            ans.push_back(
                pref[i] ^ pref[i - 1]
            );
        }
    //    for(int i = 1; i < pref.size(); i ++) {
    //         ans.push_back(preSum ^ pref[i]);
    //         preSum ^= pref[i];
    //    }  
       return ans;
    }
};