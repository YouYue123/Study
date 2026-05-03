// 3412. Find Mirror Score of a String [M]
// LeetCode find-mirror-score-of-a-string

class Solution {
public:
    long long calculateScore(string s) {
        long long ans = 0;
        unordered_map<char, stack<int>> dict;
        for(int i = 0; i < s.size(); i ++) {
            char c = s[i];
            char mirrorC = 'a' + (25 - (s[i] - 'a'));
            // cout << c << " " << mirrorC << endl;
            // cout << score << endl;
            if(dict.contains(mirrorC)) {
                ans += i - dict[mirrorC].top();
                dict[mirrorC].pop();
                if(dict[mirrorC].empty()) dict.erase(mirrorC);
            } else {
                dict[c].push(i);
            }
        }
        return ans;
    }
};