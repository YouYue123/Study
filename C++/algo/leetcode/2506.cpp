// 2506. Count Pairs Of Similar Strings [E]
// LeetCode count-pairs-of-similar-strings

class Solution {
public:
    int getKey(string& x) {
        int ans = 0;
        for(char c : x) {
            ans |= 1 << (c - 'a');
        }
        return ans;
    }
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> dict;
        int ans = 0;
        for(string& w : words) {
            int key = getKey(w);
            ans += dict[key];
            dict[key] += 1;
        }
        return ans;
    }
};