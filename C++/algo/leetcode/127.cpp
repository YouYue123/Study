// 127. Word Ladder [H]
// LeetCode word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.contains(endWord)) return 0;
        queue<pair<string, int>> q;
        q.emplace(beginWord, 1);
        // unordered_set<string> visited
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto [ str, step ] = q.front();
                // cout << str << " " << step << endl;
                q.pop();
                if(str == endWord) return step;
                string origin = str;
                for(int j = 0; j < origin.size(); j ++) {
                    for(int k = 0; k < 26; k ++) {
                        if(origin[j] == k + 'a') continue;
                        str[j] = k + 'a';
                        if(dict.contains(str)) {
                            q.emplace(str, step + 1);
                            dict.erase(str);
                        }
                        str[j] = origin[j];
                    }
                }
            }
        }
        return 0;
    }
};