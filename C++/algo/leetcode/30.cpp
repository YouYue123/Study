// 30. Substring with Concatenation of All Words [H]
// LeetCode substring-with-concatenation-of-all-words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0 || s.size() < words.front().size() * words.size()) return {};
        unordered_map<string, int> dict;
        for(string& s : words) dict[s] += 1;
        int wLen = words[0].size();
        vector<int> ans;
        for(int i = 0; i < wLen; i ++) {
            int left = i, right = i;
            unordered_map<string, int> windowDict;
            int cnt = 0;
            while(right <= s.size() - wLen) {
                string cur = s.substr(right, wLen);
                if(dict.contains(cur)) {
                    cnt += 1;
                    windowDict[cur] += 1;
                    while(dict[cur] < windowDict[cur]) {
                        string leftS = s.substr(left, wLen);
                        windowDict[leftS] -= 1;
                        cnt -= 1;
                        left += wLen;
                    }
                    if(cnt == words.size()) {
                        ans.push_back(left);
                        string leftS = s.substr(left, wLen);
                        windowDict[leftS] -= 1;
                        left += wLen;
                        cnt -= 1;
                    }
                } else {
                    left = right + wLen;
                    cnt = 0;
                    windowDict.clear(); 
                }
                right += wLen;
            }
        }
        return ans;
    }
};