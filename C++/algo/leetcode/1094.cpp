// 1094. Car Pooling [M]
// LeetCode car-pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxEle = 0;
        for(auto& t : trips) {
            maxEle = max(maxEle, t[2]);
        }
        vector<int> diff(maxEle + 2, 0);
        for(auto& t : trips) {
            int num = t[0], from = t[1], to = t[2];
            diff[from + 1] += num;
            diff[to + 1] -= num;
        }
        int cur = 0;
        for(int i = 0; i <= maxEle; i ++) {
            cur += diff[i];
            // cout << cur << " ";
            if(cur > capacity) return false;
        }
        return true;
    }
};