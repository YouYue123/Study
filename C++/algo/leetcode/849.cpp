// 849. Maximize Distance to Closest Person [M]
// LeetCode maximize-distance-to-closest-person

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> leftDist(seats.size(), INT_MAX);
        vector<int> rightDist(seats.size(), INT_MAX);
        int prev = -1;
        for(int i = 0; i < seats.size() ; i ++) {
            if(seats[i] == 1) prev = i;
            if(prev != -1) leftDist[i] = abs(i - prev);
        }
        prev = -1;
        for(int i = seats.size() - 1; i >=0; i --) {
            if(seats[i] == 1) prev = i;
            if(prev != -1) rightDist[i] = abs(i - prev);
        }
        int ans = 0;
        for(int i = 0; i < seats.size(); i ++) {
            // cout << "i: " << i << endl;
            // cout << "leftDist: " << leftDist[i] << " rightDist: " << rightDist[i] << endl;
            if(seats[i] == 0)  {
                ans = max(ans, min(leftDist[i], rightDist[i]));
            }
        }
        return ans;
    }
};