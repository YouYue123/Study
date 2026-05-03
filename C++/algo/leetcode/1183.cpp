// 1183. Maximum Number of Ones [H]
// LeetCode maximum-number-of-ones

class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int w = width / sideLength, h = height / sideLength;
        int wr = width % sideLength, hr = height % sideLength;
        int res = w * h * maxOnes;

        /// handle corner
        int count = maxOnes;
        int corner = wr * hr;
        res += min(corner, count) * (w + h + 1 );
        count -= min(corner, count);

        /// count bottom and right side
        int bottom = wr * (sideLength - hr);
        int right = hr * (sideLength - wr);

        if (w > h) {
            res += min(right, count) * w;
            count -= min(right, count);
            return res += min(bottom, count) * h;
        }
        else {
            res += min(bottom, count) * h;
            count -= min(bottom, count);
            return res += min(right, count) * w;
        }
    }
};