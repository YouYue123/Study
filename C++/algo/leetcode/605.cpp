// 605. Can Place Flowers [E]
// LeetCode can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        for(int i = 0; i < flowerbed.size(); i ++) {
            if(flowerbed[i] == 0) {
                bool isEmptyLeft = (i == 0) || flowerbed[i - 1] == 0;
                bool isEmptyRight = (i == flowerbed.size() - 1) || flowerbed[i + 1] == 0;
                if(isEmptyLeft && isEmptyRight) {
                    flowerbed[i] = 1;
                    n -= 1;
                }
            }
        }
        return n <= 0;
    }
};