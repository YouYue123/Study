// 2513. Minimize the Maximum of Two Arrays [M]
// LeetCode minimize-the-maximum-of-two-arrays

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long lcm = std::lcm((long long)divisor1, (long long)divisor2);
        long long left = 0; 
        long long right = ((long long)uniqueCnt1 + uniqueCnt2) * max(divisor1, divisor2);
        auto isValid = [&] (long long mid) {
            long long arr1Max = mid - mid / divisor1;
            long long arr2Max = mid - mid / divisor2;
            long long totalMax = mid - mid / lcm;
            return uniqueCnt1 <= arr1Max && uniqueCnt2 <= arr2Max && (uniqueCnt1 + uniqueCnt2) <= totalMax;
        };
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(!isValid(mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};