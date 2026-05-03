// 1394. Find Lucky Integer in an Array [E]
// LeetCode find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int maxFreq = INT_MIN;
        int ans = -1;
        for(int num : arr) {
            freq[num] += 1;
        }
        for(auto& p : freq) {
            if(p.first == p.second && maxFreq < p.second) {
                ans = p.first;
                maxFreq = p.second;
            }
        }
        return ans;
    }
};