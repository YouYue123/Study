// 2063. Vowels of All Substrings [M]
// LeetCode vowels-of-all-substrings

class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        unordered_set dict = {
            'a', 'e', 'i', 'o', 'u'
        };
        auto isVowel = [&] (char c) {
            return dict.contains(c);
        };
        vector<long long> dp(n, 0LL);
        for(int i = 0; i < n; i ++) {
            if(!isVowel(word[i])) {
                dp[i] = i >= 1 ? dp[i - 1] : 0;
            } else {
                dp[i] = i >= 1 ? dp[i - 1] + i + 1 : 1;
            }
        }
        long long ans = 0;
        for(long long item : dp ) ans += item;
        return ans;
    }
};