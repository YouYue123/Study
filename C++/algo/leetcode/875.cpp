// 875. Koko Eating Bananas [M]
// LeetCode koko-eating-bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size() > h) return -1;
        int max_elem = *max_element(piles.begin(), piles.end());
        int left = 0, right = max_elem + 1;
        auto isValid = [&] (int x) -> bool {
            long long cnt = 0;
            for(int pile : piles) {
                if(pile % x == 0) {
                    cnt += pile / x;
                } else {
                    cnt += pile / x + 1;
                }
            }
            return cnt <= h;
        };
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left + 1;
    }
};