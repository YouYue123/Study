// 1234. Replace the Substring for Balanced String [M]
// LeetCode replace-the-substring-for-balanced-string

class Solution {
public:
    bool isOutsideGood( unordered_map<char, int>& dict, int desire) {
        string s = "QWER";
        for(char c : s) {
            if(dict[c] > desire) return false;
        }
        return true;
    }
    int balancedString(string s) {
        int desire = s.size() / 4;
        int left = 0, right = 0;
        unordered_map<char, int> dict;
        for(char c : s) dict[c] += 1;
        int ans = INT_MAX;
        while(right < s.size()) {
            dict[s[right]] -= 1;
            // cout << dict['Q'] << " " << dict['W'] << " " << dict['E'] << " " << dict['R'] << endl; 
            while(left < s.size() && isOutsideGood(dict, desire)) {
                // cout << "good" << endl;
                // cout << left << " " << right << endl;
                ans = min(ans, right - left + 1);
                dict[s[left]] += 1;
                left += 1;
            }
            right += 1;
        }
        return ans;
    }
};