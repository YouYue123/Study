// 3085. Minimum Deletions to Make String K-Special [M]
// LeetCode minimum-deletions-to-make-string-k-special

class Solution {
public:
    int minimumDeletions(string word, int k) {
        // abs(freq[word[i]] - freq[word[j]]) <= k
        // aabcaba, k = 0
        // 4a 2b 1c 
        // dabdcbdcdcd, k = 2;
        // 1a 2b 3c 5d
        // aaabaaa, k = 2
        // 6a 1b
        vector<int> freq(26, 0);
        int ans = INT_MAX;
        for(char c : word) freq[c - 'a'] += 1;
        for(int i = 0; i < 26; i ++) {
            if(freq[i] == 0) continue;
            int target = freq[i];
            int temp = 0;
            for(int j = 0; j < 26; j ++) {
                if(i == j) continue;
                if(freq[j] < target) {
                    temp += freq[j];
                } else if(freq[j] >= target + k) {
                    temp += freq[j] - (target + k);
                }
            }
            // cout << temp << endl;
            ans = min(ans, temp);
        }
        return ans;
    }
};