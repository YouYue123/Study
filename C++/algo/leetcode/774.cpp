// 774. Minimize Max Distance to Gas Station [H]
// LeetCode minimize-max-distance-to-gas-station

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        auto isValid = [&](double x) {
            int cnt = 0;
            for(int i = 1; i < stations.size(); i ++) {
                cnt += (double)((stations[i] - stations[i - 1]) / x);
            }
            // cout << x << " " << cnt << endl;
            return cnt <= k;
        };
        double left = 0.0;
        double right = 1e8;
        while(right - left > 1e-6) {
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