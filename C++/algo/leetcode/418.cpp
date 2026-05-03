// 418. Sentence Screen Fitting [M]
// LeetCode sentence-screen-fitting

class Solution {
public:
     int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        int words = 0;
        unordered_map<int, int> umap;
        for(int i=0; i<rows; i++){
            int start = words % n;
            if(umap.count(start)) words += umap[start];
            else{
                int addedWordCnt=0; 
                for(int j=start, len=0; len<=cols; j=(j+1)%n , addedWordCnt++){
                    if(len+sentence[j].size() > cols)
                        break;
                    else
                        len += sentence[j].size() + 1;
                }
                words += addedWordCnt;
                umap[start] = addedWordCnt;
            }
        }
        return words/n;
    }
};