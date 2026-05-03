// 3325. Count Substrings With K-Frequency Characters I [M]
// LeetCode count-substrings-with-k-frequency-characters-i

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int left = 0, right = 0;
        int count = 0;
        unordered_map<char, int> dict;
        int ans = 0;
        while(right < s.size()) {
            dict[s[right]] += 1;
            if(dict[s[right]] == k) count += 1;
            while(count >= 1) {
                dict[s[left]] -= 1;
                if(dict[s[left]] == k - 1) count -= 1;
                left += 1;
            }
            ans += left;
            right += 1;
        }
        return ans;
    }
};