// 2085. Count Common Words With One Occurrence [E]
// LeetCode count-common-words-with-one-occurrence

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> cnt1;
        unordered_map<string, int> cnt2;
        for(auto& w : words1) cnt1[w] += 1;
        for(auto& w : words2) cnt2[w] += 1;
        int ans = 0;
        for(auto [w, cnt] : cnt1) {
            if(cnt == 1 && cnt2[w] == 1) ans += 1;
        }
        return ans;
    }
};