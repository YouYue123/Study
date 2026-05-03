// 2048. Next Greater Numerically Balanced Number [M]
// LeetCode next-greater-numerically-balanced-number

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int ans = n + 1;
        while(true) {
            int cnt[10] = {};
            for(int x = ans; x > 0; x /= 10) {
                cnt[x % 10] += 1;
            }
            bool ok = true;
            for(int x = ans; x > 0; x /= 10) {
                if(cnt[x % 10] != (x % 10)) {
                    ok = false;
                    break;
                }
            }
            if(ok) return ans;
            ans += 1;
        }   
        return ans;
    }
};