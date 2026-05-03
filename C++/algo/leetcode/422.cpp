// 422. Valid Word Square [E]
// LeetCode valid-word-square

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        // int m = words.size(), n = words[0].size();
        for(int i = 0; i < words.size(); i ++) {
            for(int j = 0; j < words[i].size(); j ++) {
                // cout << i << " " << j << endl;
                // cout << words[i][j] << endl;
                if(!isalpha(words[i][j])) continue;
                if(j >= words.size() || i >= words[j].size()) return false;
                if(words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};