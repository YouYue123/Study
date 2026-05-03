// 2743. Count Substrings Without Repeating Character [M]
// LeetCode count-substrings-without-repeating-character

class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> dict;
        int count = 0;
        int ans = 0;
        while(right < s.size()) {
            if(dict[s[right]] == 1) count += 1;
            dict[s[right]] += 1;
            while(count > 0) {
                if(dict[s[left]] > 1) count -= 1;
                dict[s[left]] -= 1;
                left += 1;
            }
            // cout << left << " " << right << endl;
            ans += right - left + 1;
            right += 1;
        }
        return ans;
    }
};