// 137. Single Number II [M]
// LeetCode single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        // cout << (0 | (1 << 3)) << endl;
        for(int i = 0; i < 32; i ++) {
            int cnt = 0;
            for(int num : nums) {
                if((num >> i) & 1) cnt += 1;
            }
            if(cnt % 3 == 1) {
                cout << "set " << i << endl;
                ans |= (1 << i);
            } 
        }
        return ans;
    }
};