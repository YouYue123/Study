// 3516. Find Closest Person [E]
// LeetCode find-closest-person

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int gapX = abs(z - x);
        int gapY = abs(z - y);
        if(gapX == gapY) return 0;
        else if(gapX > gapY) return 2;
        else return 1;
    }
};