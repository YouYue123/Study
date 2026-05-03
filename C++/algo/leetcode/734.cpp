// 734. Sentence Similarity [E]
// LeetCode sentence-similarity

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;
        unordered_map<string, unordered_map<string, bool>> dict;
        for(auto& p : similarPairs) {
            dict[p[0]][p[1]] = true;
            dict[p[1]][p[0]] = true;
        }
        for(int i = 0; i < sentence1.size(); i ++) {
            string s1 = sentence1[i];
            string s2 = sentence2[i];
            if(dict[s1][s2] || dict[s2][s1] || s1 == s2) continue;
            else return false;
        }
        return true;
    }
};