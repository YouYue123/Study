// 1358. Number of Substrings Containing All Three Characters [M]
// LeetCode number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> dict;
        int left = 0, right = 0;
        int cnt = 0;
        int ans = 0;
        while(right < n) {
            dict[s[right]] += 1;
            if(dict[s[right]] == 1) cnt += 1;
            while(cnt == 3) {
                ans += n - right;
                dict[s[left]] -= 1;
                if(dict[s[left]] == 0) cnt -= 1;
                left += 1;
            }
            right += 1;
        }
        return ans;
    }
};