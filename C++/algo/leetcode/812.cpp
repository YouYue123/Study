// 812. Largest Triangle Area [E]
// LeetCode largest-triangle-area

class Solution {
    double area(vector<int>& a, vector<int>& b, vector<int>& c) {
        double twice_signed_area = (double)a[0] * (b[1] - c[1]) + 
                               (double)b[0] * (c[1] - a[1]) + 
                               (double)c[0] * (a[1] - b[1]);                               
        return abs(twice_signed_area) / 2.0;
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.0;
        for(int i = 0; i < points.size(); i ++) {
            for(int j = i + 1; j < points.size(); j ++) {
                for(int k = j + 1; k < points.size(); k ++) {
                    ans = max(ans, area(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
};