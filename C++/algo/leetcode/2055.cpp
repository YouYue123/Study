// 2055. Plates Between Candles [M]
// LeetCode plates-between-candles

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> leftCandle(s.size(), 0);
        vector<int> rightCandle(s.size(), 0);
        vector<int> preSum(s.size() + 1, 0);
        int curLeft = -1, curRight = -1;
        for(int i = 0; i < s.size(); i ++) {
            int j = s.size() - 1 - i;
            if(s[i] == '|') curLeft = i;
            if(s[j] == '|') curRight = j;
            leftCandle[i] = curLeft;
            rightCandle[j] = curRight;
            preSum[i + 1] = preSum[i] + (s[i] == '*');

        }
        vector<int> ans;
        for(vector<int>& q : queries) {
            int x = rightCandle[q[0]], y = leftCandle[q[1]];
            if(x == -1 || y == -1 || x >= y) {
                ans.push_back(0);
            } else {
                ans.push_back(preSum[y + 1] - preSum[x]);
            }
            
        }
        return ans;
    }
};