// 1464. Maximum Product of Two Elements in an Array [E]
// LeetCode maximum-product-of-two-elements-in-an-array

class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int biggest = 0;
        int secondBiggest = 0;
        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = max(secondBiggest, num);
            }
        }
        
        return (biggest - 1) * (secondBiggest - 1);
    }
};