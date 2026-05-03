// 2200. Find All K-Distant Indices in an Array [E]
// LeetCode find-all-k-distant-indices-in-an-array

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyPos;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] == key) keyPos.push_back(i);
        }
        if(keyPos.size() == 0) return {};
        int left = 0, right = min(1, (int)keyPos.size());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i ++) {
            if(right < keyPos.size() && i >= keyPos[right]) {
                left += 1;
                right += 1;
            }
            if(left < keyPos.size() && abs(i - keyPos[left]) <= k) {
                ans.push_back(i);
            } else if(right < keyPos.size() && abs(i - keyPos[right]) <= k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};