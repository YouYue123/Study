// 3875. Construct Uniform Parity Array I [E]
// LeetCode construct-uniform-parity-array-i

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even_cnt = 0, odd_cnt = 0;
        for(int num : nums1) {
            bool isEven = (num % 2 == 0 );
            if(isEven) {
                even_cnt += 1;
            } else {
                odd_cnt += 1;
            }
        }
        bool can_all_odd = true, can_all_even = true;
        for(int num : nums1) {
            bool isEven = (num % 2 == 0);
            if(isEven) {
                // try to convert even to odd
                if(odd_cnt == 0) {
                    can_all_odd = false;
                }
            } else {
                // try to convert odd to even
                if(odd_cnt <= 1) {
                    can_all_even = false;
                }
            }
        }
        // cout << "can_all_odd: " << can_all_odd << " can_all_even: " << can_all_even << endl;
        return can_all_odd || can_all_even;
    }
};