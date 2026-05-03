// 760. Find Anagram Mappings [E]
// LeetCode find-anagram-mappings

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> dict;
        for(int i = 0 ; i< nums2.size(); i++) {
            dict[nums2[i]] = i;
        }
        for(int i = 0; i < nums1.size(); i ++) {
            ans.push_back(dict[nums1[i]]);
        }
        return ans;
    }
};