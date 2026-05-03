// 1518. Water Bottles [E]
// LeetCode water-bottles

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyCnt = 0;
        int ans = 0;
        while(numBottles > 0 || emptyCnt >= numExchange) {
            ans += numBottles;
            emptyCnt += numBottles;
            numBottles = 0;
            numBottles += emptyCnt / numExchange;
            emptyCnt %= numExchange;
        }
        return ans;
    }
};