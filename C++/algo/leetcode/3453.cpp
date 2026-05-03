// 3453. Separate Squares I [M]
// LeetCode separate-squares-i

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        auto isValid = [&] (double mid) {
            double top = 0.0, bottom = 0.0;
            for(auto& s : squares) {
                double y = s[1], len = s[2];
                double area = len * len;
                if(y >= mid) {
                    top += area;
                } else if(y + len <= mid) {
                    bottom += area;
                } else {
                    top += (y + len - mid) * len;
                    bottom += (mid - y) * len; 
                }
            }
            return top <= bottom;
        };
        double left = 0.0, right = 1e9 + 1;
        while(right - left > 1e-5) {
            double mid = left + (right - left) / 2.0;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};