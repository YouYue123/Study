// 3100. Water Bottles II [M]
// LeetCode water-bottles-ii

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyCnt = 0;
        int ans = 0;
        while(numBottles > 0 || emptyCnt >= numExchange) {
            ans += numBottles;
            emptyCnt += numBottles;
            numBottles = 0;
            while(emptyCnt >= numExchange) {
                numBottles += 1;
                emptyCnt -= numExchange;
                numExchange += 1;
            }
        }
        return ans;
    }
};