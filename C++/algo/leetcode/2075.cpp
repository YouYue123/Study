// 2075. Decode the Slanted Ciphertext [M]
// LeetCode decode-the-slanted-ciphertext

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col_cnt = n / rows;
        // cout << col_cnt << endl;
        string ans = "";
        for(int col = 0; col < col_cnt ; col ++) {
            int cur_row = 0;
            int cur_col = col;
            int idx =  cur_row * col_cnt + cur_col;
            // if(encodedText[idx] == ' ') break;
            // cout << row << " " << col << endl;
            while(idx < n) {
                // cout << idx << endl; 
                ans += encodedText[idx];
                cur_row += 1;
                cur_col += 1;
                idx = cur_row * col_cnt + cur_col;
            }
        }
        // Find the last character that is NOT a space
        auto it = std::ranges::find_if(ans | std::views::reverse, [](unsigned char ch) {
            return !std::isspace(ch);
        }).base();

        ans.erase(it, ans.end());
        // trim
        return ans;
    }
};