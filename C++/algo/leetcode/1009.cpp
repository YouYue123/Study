// 1009. Complement of Base 10 Integer [E]
// LeetCode complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        // int ans = 0;
        // vector<int> comples;
        // while(n > 0) {
        //     int d = n % 2;
        //     int comple = d ^ 1;
        //     comples.push_back(comple);
        //     n /= 2;
        // }
        // for(int i= comples.size() - 1; i >= 0; i --) {
        //     ans = ans * 2 + comples[i];
        // }
        // return ans;
        int len = (int)(log(n) / log(2)) + 1;
        int bit = (1 << len) - 1;
        return bit ^ n;
    }
};