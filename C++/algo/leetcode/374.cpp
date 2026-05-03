// 374. Guess Number Higher or Lower [E]
// LeetCode guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int ans = guess(mid);
            if(ans <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};