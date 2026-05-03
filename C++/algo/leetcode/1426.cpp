// 1426. Counting Elements [E]
// LeetCode counting-elements

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, bool> dict;
        for (auto item : arr) {
            dict[item] = true;
        }
        int ans = 0;
        for (auto item : arr) {
            if(dict[item + 1]) {
                ans += 1;
            }
        }
        return ans;
    }
};