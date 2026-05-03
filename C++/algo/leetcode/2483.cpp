// 2483. Minimum Penalty for a Shop [M]
// LeetCode minimum-penalty-for-a-shop

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int p = 0;
        int ans = 0;
        int minP = 0;
        for(int i = 0; i < n; i ++) {
            char c = customers[i];
            if(c == 'Y') p -= 1;
            else p += 1;
            if(minP > p) {
                ans = i + 1;
                minP = p;
            }
        }
        return ans;
    }
};