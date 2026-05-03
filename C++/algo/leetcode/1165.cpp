// 1165. Single-Row Keyboard [E]
// LeetCode single-row-keyboard

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> dict;
        for(int i = 0; i < keyboard.size(); i ++) {
            char c = keyboard[i];
            dict[c] = i;
        }
        int ans = 0;
        int prev = 0;
        for(char c : word) {
            // cout << dict[c] << endl;
            ans += abs(dict[c] - prev);
            prev = dict[c];
        }
        return ans;
    }
};