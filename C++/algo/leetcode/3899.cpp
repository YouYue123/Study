// 3899. Angles of a Triangle [M]
// LeetCode angles-of-a-triangle

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        vector<double> ans;
        if(sides[0] + sides[1] > sides[2]) {
            double a = sides[0], b = sides[1], c = sides[2];
            double rad_a = acos((b * b + c * c - a * a) / (2.0 * b * c));
            double rad_b = acos((a * a + c * c - b * b) / (2.0 * a * c));
            double rad_c = acos((a * a + b * b - c * c) / (2.0 * a * b));
            double factor = 180.0 / M_PI;
            ans.push_back(rad_a * factor);
            ans.push_back(rad_b * factor);
            ans.push_back(rad_c * factor);
            sort(ans.begin(), ans.end());
            return ans;
        } else {
            return ans;
        }
    }
};