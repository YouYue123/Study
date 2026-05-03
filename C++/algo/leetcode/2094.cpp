// 2094. Finding 3-Digit Even Numbers [E]
// LeetCode finding-3-digit-even-numbers

class Solution {
public:
    vector<int> ans;
    vector<int> digits;
    unordered_map<int, bool> visited;
    void dfs(int pos, int temp) {
        // cout << pos << " " << temp << endl;
        if(temp * 10 >= 1000) {
            if(temp % 2 == 0) ans.push_back(temp);
            return;
        } 
        for(int i = 0; i < digits.size(); i ++) {
            if(temp == 0 && digits[i] == 0) continue;
            if(visited[i]) continue;
            if(i > 0 && digits[i] == digits[i - 1] && !visited[i -1]) continue;
            visited[i] = true;
            dfs(i + 1, temp * 10 + digits[i]);
            visited[i] = false;
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        this->digits = digits;
        sort(this->digits.begin(), this->digits.end());
        dfs(0, 0);
        // sort(ans.begin(), ans.end());
        return ans;
    }
};