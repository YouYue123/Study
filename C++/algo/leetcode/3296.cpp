// 3296. Minimum Number of Seconds to Make Mountain Height Zero [M]
// LeetCode minimum-number-of-seconds-to-make-mountain-height-zero

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto isValid = [&](long long x) {
            long long totalLowered = 0;
            for (int t : workerTimes) {
                double d_x = (double)x;
                double d_t = (double)t;
                double cnt = (-d_t + sqrt(d_t * d_t + 8.0 * d_t * d_x)) / (2.0 * d_t);
                
                totalLowered += (long long)floor(cnt);
                
                if (totalLowered >= mountainHeight) return true; // 提前退出，防止 long long 也溢出
            }
            return totalLowered >= mountainHeight;
        };
        int min_woker_time = *min_element(workerTimes.begin(), workerTimes.end());
        long long left = 0;
        long long right = (1LL * mountainHeight * (mountainHeight + 1) / 2) * min_woker_time;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            if (isValid(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left + 1;
    }
};