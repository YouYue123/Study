// 2001. Number of Pairs of Interchangeable Rectangles [M]
// LeetCode number-of-pairs-of-interchangeable-rectangles

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, unordered_map<int, int>> dict;
        long long ans = 0;
        for(auto& r: rectangles) {
            int w = r[0], h = r[1];
            int gcd = __gcd(w, h);
            // cout << gcd << endl;
            w = w / gcd, h = h / gcd;
            // cout << w << " " << h << endl;
            ans += dict[w][h];
            dict[w][h] += 1;
        }
        return ans;
    }
};