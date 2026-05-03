// 3876. Construct Uniform Parity Array II [M]
// LeetCode construct-uniform-parity-array-ii

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_cnt = 0, even_cnt = 0;
        int odd_min = INF;
        for(int num : nums1) {
            if(num % 2 == 0) {
                even_cnt += 1;
            } else {
                odd_cnt += 1;
                odd_min = min(odd_min, num);
            }
        }
        bool can_all_odd = true, can_all_even = true;
        for(int num : nums1) {
            if(num % 2 == 0) {
                // try to convert to odd
                if(odd_cnt == 0 || odd_min >= num) {
                    can_all_odd = false; 
                }
            } else {
                // try to convert to even
                if(odd_cnt <= 1 || odd_min >= num) {
                    can_all_even = false;
                }
            }
        }
        return can_all_odd || can_all_even;
    }
};